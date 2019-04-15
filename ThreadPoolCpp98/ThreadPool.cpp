#include "ThreadPool.h" 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

namespace zl
{
    ThreadPool::ThreadPool(int threadNum)//构造
    {
        isRunning_ = true;
        threadsNum_ = threadNum;
        createThreads();
    }

    ThreadPool::~ThreadPool()//析构
    {
        stop();
        for(std::deque<Task*>::iterator it = taskQueue_.begin(); it != taskQueue_.end(); ++it)
        {
            delete *it;
        }
        taskQueue_.clear();
    }

    int ThreadPool::createThreads()//创建线程池，每个线程执行threadFunc
    {
        pthread_mutex_init(&mutex_, NULL);
        pthread_cond_init(&condition_, NULL);
        threads_ = (pthread_t*)malloc(sizeof(pthread_t) * threadsNum_);
        for (int i = 0; i < threadsNum_; i++)
        {
            pthread_create(&threads_[i], NULL, threadFunc, this);
        }
        return 0;
    }

    size_t ThreadPool::addTask(Task *task)//向任务队列中添加任务
    {
        pthread_mutex_lock(&mutex_);
        taskQueue_.push_back(task);
        int size = taskQueue_.size();
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&condition_);
        return size;
    }

    void ThreadPool::stop()//终止
    {
        if (!isRunning_)
        {
            return;
        }

        isRunning_ = false;
        pthread_cond_broadcast(&condition_);

        for (int i = 0; i < threadsNum_; i++)
        {
            pthread_join(threads_[i], NULL);
        }

        free(threads_);
        threads_ = NULL;

        pthread_mutex_destroy(&mutex_);
        pthread_cond_destroy(&condition_);
    }

    int ThreadPool::size()//返回任务队列的长度
    {
        pthread_mutex_lock(&mutex_);
        int size = taskQueue_.size();
        pthread_mutex_unlock(&mutex_);
        return size;
    }

    Task* ThreadPool::take()//获取任务队列头部的任务
    {
        Task* task = NULL;
        while (!task)
        {
            pthread_mutex_lock(&mutex_);
            while (taskQueue_.empty() && isRunning_)
            {
                pthread_cond_wait(&condition_, &mutex_);
            }

            if (!isRunning_)
            {
                pthread_mutex_unlock(&mutex_);
                
                break;
            }
            else if (taskQueue_.empty())
            {
                pthread_mutex_unlock(&mutex_);
                continue;
            }

            assert(!taskQueue_.empty());
            task = taskQueue_.front();
            taskQueue_.pop_front();
            pthread_mutex_unlock(&mutex_);
        }
        return task;
    }

    void* ThreadPool::threadFunc(void* arg)
    {
        pthread_t tid = pthread_self();
        ThreadPool* pool = static_cast<ThreadPool*>(arg);
        while (pool->isRunning_)
        {
            Task* task = pool->take();//从任务队列的头部去一个任务
            if (!task)
            {
                printf("thread %lu will exit\n", tid);
                break;
            }

            assert(task);
            task->run();
        }
        return 0;
    }

}
