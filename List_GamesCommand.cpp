
#include <unistd.h>
#include "List_GamesCommand.h"
#define MAX_COMMAND_LEN 50

void List_GamesCommand::execute(vector<string> args, int socket) {
    GamesManager *gamesManager=GamesManager::getInstance();
    vector <string> names;
    names=gamesManager->getListOfActiveGames();
    long size=names.size();
    int n =write(socket,&size,sizeof(size));
    if (n == -1){
        cout<<"Error reading command"<<endl;
        close(socket);
        return;
    }
    if (n == 0){
        cout << "Client disconnected" << endl;
        close(socket);
        return;
    }
    for(int i=0;i<names.size();i++) {
        int n =write(socket,&names[i],MAX_COMMAND_LEN);
        if (n == -1){
            cout<<"Error reading command"<<endl;
            close(socket);
            return;
        }
        if (n == 0){
            cout << "Client disconnected" << endl;
            close(socket);
            return;
        }
    }
    close(socket);
}
