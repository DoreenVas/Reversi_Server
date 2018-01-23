
#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <vector>
#include <sys/param.h>
#include <string>
#include "Task.h"
#include "ThreadPool.h"

using namespace std;


/*****************************************************************************************************
* class name: Server
* description: connects with clients
******************************************************************************************************/
class Server {
public:
/***************************************************************************************************
* constructor name:Server
* the input: int port
* the output: none
* the function operation:initializes the port variable to the one he got and the serverSocket variable to zero
***************************************************************************************************/
    Server(int port);

/***************************************************************************************
* function name: start
* the input: none
* the output: none
* the function operation:creates the socket point, listens and accepts clients each gets a thread
 * and continue to the handleClient function.
****************************************************************************************/
    void start();

/***************************************************************************************
* function name: stop
* the input: none
* the output: none
* the function operation:closes the server socket,the server thread, then sends the
* CommandsManager a close_server command and deletes the CommandsManager instance.
****************************************************************************************/
    void stop();

    int getServerSocket() const;
    ThreadPool pool;
    vector <Task*> taskVec;

private:
    int port;
    int serverSocket;
    pthread_t serverThreadId;

};
#endif //SERVER_SERVER_H