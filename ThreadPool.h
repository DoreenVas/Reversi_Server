
#ifndef SERVER_THREADPOOL_H
#define SERVER_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

/*****************************************************************************************************
* class name: ThreadPool
* description: a pool of threads to preform tasks
******************************************************************************************************/
class ThreadPool {
public:
/***************************************************************************************************
* constructor name:ThreadPool
* the input: int threadsNum
* the output: none
* the function operation:creates threads by the number it got in an array of threads and initialized the mutex
***************************************************************************************************/
    ThreadPool(int threadsNum);
/***************************************************************************************
* function name: addTask
* the input: Task *task
* the output: none
* the function operation:adds the given task to the tasksQueue
****************************************************************************************/
    void addTask(Task *task);
/***************************************************************************************
* function name: terminate
* the input: none
* the output: none
* the function operation:changes the stopped variable to true so the executeTasks function will stop
 * also destroys the mutex
****************************************************************************************/
    void terminate();
/***************************************************************************************************
* destructor name:ThreadPool
* the input: none
* the output: none
* the function operation:deletes the threads
***************************************************************************************************/
    virtual ~ThreadPool();

private:
    queue<Task *> tasksQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;

    static void *execute(void *arg);
};


#endif //SERVER_THREADPOOL_H
