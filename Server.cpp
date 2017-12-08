
#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAX_CONNECTED_CLIENTS 2
Server::Server(int port): port(port), serverSocket(0) {
    cout << "Server" << endl;
}
void Server::start() {
    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);

    // Define the client socket's structures
    struct sockaddr_in clientAddress;
    socklen_t clientAddressLen;

    while (true) {
        // Accept new clients connections
        cout << "Waiting for the first client to connect..." << endl;
        int firstClientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
        cout << "client connected" << endl;
        if (firstClientSocket == -1) {
            throw "Error on accept first client";
        }
        cout << "Waiting for the second client to connect..." << endl;
        int secondClientSocket = accept(serverSocket, (struct sockaddr *)&clientAddress, &clientAddressLen);
        cout << "second client connected" << endl;
        if (secondClientSocket == -1) {
            //close(firstClientSocket);
            throw "Error on accept second client";
        }
        int message=FIRST_PLAYER;
        int n=write(firstClientSocket,&message,sizeof(message));
        if(!writeCheck(n))
            return;
        message=SECOND_PLAYER;
        n=write(secondClientSocket,&message,sizeof(message));
        if(!writeCheck(n))
            return;
        handleClient(firstClientSocket,secondClientSocket);
        // Close communication with the clients
        close(firstClientSocket);
        close(secondClientSocket);
    }
}

void Server::handleClient(int firstClientSocket,int secondClientSocket) {
    int row,col;
    while (true) {
        int n = read(firstClientSocket, &row, sizeof(row));
        if(!readCheck(n))
          return;
        n = read(firstClientSocket, &col, sizeof(col));
        if(!readCheck(n))
            return;
        cout << "Got move: " << row+1 << " " << col+1 << endl;
        n=write(secondClientSocket,&row,sizeof(row));
        if(!writeCheck(n))
            return;
        n=write(secondClientSocket,&col,sizeof(col));
        if(!writeCheck(n))
            return;
        cout << "Sent move"<<endl;
        swapSockets(&firstClientSocket,&secondClientSocket);
    }
}


void Server::stop() {
    close(serverSocket);
}

bool Server::readCheck(int n) {
    if (n==-1){
        cout << "Error reading from socket" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    return true;
}

bool Server::writeCheck(int n) {
    if (n==-1){
        cout << "Error writing to socket" << endl;
        return false;
    }
    if (n == 0) {
        cout << "Client disconnected" << endl;
        return false;
    }
    return true;
}

void Server::swapSockets(int *Socket1, int *Socket2) {
    int temp=*Socket1;
    *Socket1=*Socket2;
    *Socket2=temp;
}

