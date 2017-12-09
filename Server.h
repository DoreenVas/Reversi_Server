
#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#define FIRST_PLAYER 1
#define SECOND_PLAYER 2

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
    explicit Server(int port);
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
/***************************************************************************************
* function name: handleClient
* the input: two ints representing the clients sockets
* the output: none
* the function operation:reads from one socket and writes to the other, than switches
* between them with swapSockets and repeats
****************************************************************************************/
    void handleClient(int firstClientSocket,int secondClientSocket);
/***************************************************************************************
* function name: swapSockets
* the input: two int pointers to the clients sockets
* the output: none
* the function operation:switches the client we currently read from by swapping the sockets values
****************************************************************************************/
    void swapSockets(int *Socket1, int *Socket2);
/***************************************************************************************
* function name: readCheck
* the input: int n representing the value of the read
* the output: true if the reading went well, false otherwise
* the function operation:directly checking the value of n to see if it equals -1 or 0
****************************************************************************************/
    bool readCheck(int n);
/***************************************************************************************
* function name: writeCheck
* the input: int n representing the value of the write
* the output: true if the writing went well, false otherwise
* the function operation:directly checking the value of n to see if it equals -1 or 0
****************************************************************************************/
    bool writeCheck(int n);
};


#endif //SERVER_SERVER_H