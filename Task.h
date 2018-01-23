
#ifndef SERVER_TASK_H
#define SERVER_TASK_H

/*****************************************************************************************************
* class name: Task
* description: a task to preform
******************************************************************************************************/
class Task {
public:
/***************************************************************************************************
* constructor name:Task
* the input: a function and arguments
* the output: none
* the function operation:initializes the variables
***************************************************************************************************/
    Task(void * (*func)(void *arg), void* arg) :
            func(func), arg(arg) {}
/***************************************************************************************
* function name: execute
* the input: none
* the output: none
* the function operation:call the function with the arguments
****************************************************************************************/
    void execute() {
        func(arg);
    }
    virtual ~Task() {}
private:
    void * (*func)(void *arg);
    void *arg;
};


#endif //SERVER_TASK_H
