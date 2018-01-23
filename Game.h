
#ifndef SERVER_GAME_H
#define SERVER_GAME_H

#define ONE_PLAYER 10
#define TWO_PLAYER 11

#include <iostream>

using namespace std;

/*****************************************************************************************************
* class name: Game
* description: game control
******************************************************************************************************/
class Game {
public:
/***************************************************************************************
* constructor name: Game
* the input: int socket and string name
* the function operation:initializes the variables accordingly, the status is one player.
****************************************************************************************/
    Game (int firstClientSocket,string name);
/***************************************************************************************
* function name: addSecondPlayer
* the input: int socket
* the output: none
* the function operation:changes the status to two players and initializes the
* secondClientSocket with the one we received.
****************************************************************************************/
    void addSecondPlayer(int secondClientSocket);
/***************************************************************************************
* function name: play
* the input: none
* the output: none
* the function operation:reads from one socket and writes to the other, than switches
* between them with swapSockets and repeats
****************************************************************************************/
    void play();
/***************************************************************************************
* function name: endGame
* the input: none
* the output: none
* the function operation:closes the sockets and calls GamesManager deleteGame
****************************************************************************************/
    void endGame();
/***************************************************************************************
* function name: endGame
* the input: none
* the output: none
* the function operation:sends the sockets FAIL message;
****************************************************************************************/
    void serverStopMsg();
/***************************************************************************************
* function name: getPlayersStatus
* the input: none
* the output: int status
* the function operation:returns 10 if there is one player and 11 if there are two.
****************************************************************************************/
    int getPlayersStatus() const;
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

    void setThread(pthread_t i);

private:
/***************************************************************************************
* function name: swapSockets
* the input: two int pointers to the clients sockets
* the output: none
* the function operation:switches the client we currently read from by swapping the sockets values
****************************************************************************************/
    void swapSockets(int *Socket1, int *Socket2);

    int firstClientSocket, secondClientSocket;
    string roomName;
    int playersStatus;
    pthread_t thread;
};


#endif //SERVER_GAME_H
