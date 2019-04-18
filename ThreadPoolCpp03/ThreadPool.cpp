
#include "ThreadPool.h" 
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

namespace zl
{
    ThreadPool::ThreadPool(int threadNum)//构造函数
    {
        isRunning_ = true;
        threadsNum_ = threadNum;
        createThreads();
    }

    ThreadPool::~ThreadPool()//析构函数
    {
        stop();
    }

    int ThreadPool::createThreads()//创建线程池
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

    size_t ThreadPool::addTask(const Task& task)//添加任务
    {
        pthread_mutex_lock(&mutex_);
        taskQueue_.push_back(task);
        int size = taskQueue_.size();
        pthread_mutex_unlock(&mutex_);
        pthread_cond_signal(&condition_);
        return size;
    }

    void ThreadPool::stop()//销毁线程池
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

    int ThreadPool::size()
    {
        pthread_mutex_lock(&mutex_);
        int size = taskQueue_.size();
        pthread_mutex_unlock(&mutex_);
        return size;
    }

    ThreadPool::Task ThreadPool::take()
    {
        Task task = NULL;
        pthread_mutex_lock(&mutex_);
        while (taskQueue_.empty() && isRunning_)
        {
            pthread_cond_wait(&condition_, &mutex_);
        }
        
        if (!isRunning_)
        {
            pthread_mutex_unlock(&mutex_);  
            return task;
        }

        assert(!taskQueue_.empty());//检查参数是否为假
        task = taskQueue_.front();
        taskQueue_.pop_front();
        pthread_mutex_unlock(&mutex_);
        return task;
    }

    void* ThreadPool::threadFunc(void* arg)
    {
        pthread_t tid = pthread_self();
        ThreadPool* pool = static_cast<ThreadPool*>(arg);
        while (pool->isRunning_)
        {
            ThreadPool::Task task = pool->take();
            if (!task)
            {
                printf("thread %lu will exit\n", tid);
                break;
            }

            assert(task);//void assert(expression)，先判断expression，如果expression为假，则先打印错误，后终止程序
            task();//执行任务
        }
        return 0;
    }

}
