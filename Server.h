
#ifndef SERVER_SERVER_H
#define SERVER_SERVER_H

#define FIRST_PLAYER 1
#define SECOND_PLAYER 2

class Server {
public:
    explicit Server(int port);
    void start();
    void stop();
private:
    int port;
    int serverSocket; // the socket's file descriptor
    void handleClient(int firstClientSocket,int secondClientSocket);
    bool readCheck(int n);
    bool writeCheck(int n);
    //switch the client we currently read from by swapping the sockets
    void swapSockets(int *Socket1, int *Socket2);

};


#endif //SERVER_SERVER_H