
#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#include <vector>
#include <sys/param.h>
#include <string>

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
* the function operation:creates the socket point, listens and accepts clients(2 at a time) than handles them
****************************************************************************************/
    void start();

/***************************************************************************************
* function name: stop
* the input: none
* the output: none
* the function operation:closes the server socket
****************************************************************************************/
    void stop();

private:

    int port;
    int serverSocket; // the socket's file descriptor
    pthread_t serverThreadId;

};
#endif //SERVER_SERVER_H