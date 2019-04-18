#pragma once  
#include <deque>  
#include <pthread.h>
#include <functional>      // for std::function, std::bind

// 使用C++03/C++0x 语言规范实现的线程池： 基于对象做法，每一个job都是一个function对象

// 其他和之前完全相同，所不同的是将每个任务改成了一个function对象
namespace zl
{
    class ThreadPool
    {
    public:
        typedef std::function<void()> Task;//定义一个函数对象，返回值为void，没有输入参数，可以接受任意参数列表。。

    public:
        ThreadPool(int threadNum = 10);
        ~ThreadPool();

    public:
        size_t addTask(const Task& task);
        void   stop();
        int    size();
        Task take();

    private:
        int createThreads();
        static void* threadFunc(void * threadData);//同样是静态函数

    private:
        ThreadPool& operator=(const ThreadPool&);
        ThreadPool(const ThreadPool&);

    private:
        volatile  bool              isRunning_;
        int                         threadsNum_;
        pthread_t*                  threads_;

        std::deque<Task>            taskQueue_;//任务队列存储function对象
        pthread_mutex_t             mutex_;
        pthread_cond_t              condition_;
    };
}  
