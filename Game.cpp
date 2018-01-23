
#include "Game.h"
#include "GamesManager.h"
#include <unistd.h>

#define FIRST_PLAYER 1
#define SECOND_PLAYER 2
#define FAIL -1

using namespace std;

Game::Game(int firstClientSocket, string name) {
    this->firstClientSocket=firstClientSocket;
    this->secondClientSocket=0;
    roomName=name;
    playersStatus=ONE_PLAYER;
}

void Game::play() {
    int row,col;
    int message = FIRST_PLAYER;
    int n = write(firstClientSocket, &message, sizeof(message));
    if (!writeCheck(n)) {
        endGame();
        return;
    }
    message = SECOND_PLAYER;
    n = write(secondClientSocket, &message, sizeof(message));
    if (!writeCheck(n)){
        endGame();
        return;
    }
    while (true) {
        int n = read(firstClientSocket, &row, sizeof(row));
        if(!readCheck(n))
            break;
        n = read(firstClientSocket, &col, sizeof(col));
        if(!readCheck(n))
            break;
        cout << "Got move: " << row+1 << " " << col+1 << endl;
        n=write(secondClientSocket,&row,sizeof(row));
        if(!writeCheck(n))
            break;
        n=write(secondClientSocket,&col,sizeof(col));
        if(!writeCheck(n))
            break;
        cout << "Sent move"<<endl;
        swapSockets(&firstClientSocket,&secondClientSocket);
    }
    endGame();
}

void Game::addSecondPlayer(int secondClientSocket) {
        this->secondClientSocket = secondClientSocket;
        playersStatus=TWO_PLAYER;
}

void Game::endGame() {
    if(playersStatus==ONE_PLAYER)
        close(firstClientSocket);
    else{
        close(firstClientSocket);
        close(secondClientSocket);
    }
    pthread_cancel(thread);
    GamesManager::getInstance()->deleteGame(roomName,this);
}

bool Game::readCheck(int n) {
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

bool Game::writeCheck(int n) {
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

void Game::swapSockets(int *Socket1, int *Socket2) {
    int temp=*Socket1;
    *Socket1=*Socket2;
    *Socket2=temp;
}

int Game::getPlayersStatus() const {
    return playersStatus;
}

void Game::serverStopMsg() {
    int msg=FAIL;
    if(playersStatus==ONE_PLAYER) {
        write(firstClientSocket, &msg, sizeof(msg));//no check, doesn't matter
    }
    else{
        write(firstClientSocket, &msg, sizeof(msg));
        write(secondClientSocket, &msg, sizeof(msg));
    }
}

void Game::setThread(pthread_t thread1) {
    thread=thread1;
}

