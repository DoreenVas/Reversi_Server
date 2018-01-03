
#include <unistd.h>
#include "List_GamesCommand.h"
#define MAX_COMMAND_LEN 50

void List_GamesCommand::execute(vector<string> args, int socket) {
    GamesManager *gamesManager=GamesManager::getInstance();
    vector <string> names;
    names=gamesManager->getListOfActiveGames();
    int size=names.size();
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
       try{
           sendName(names[i],socket);
       } catch (const char *msg) {
           cout<<msg;
           close(socket);
           cout << "Client disconnected" << endl;
           return;
       }
    }
    close(socket);
    cout << "Client disconnected" << endl;
}

void List_GamesCommand::sendName(string &name,int socket) {
    const char *temp=name.c_str();
    char com[MAX_COMMAND_LEN];
    for(int i=0;i<MAX_COMMAND_LEN;i++){
        if(i<name.size())
            com[i]=temp[i];
        else
            com[i]='\0';
    }
    int n=write(socket,com,sizeof(com));
    if (n==-1){
        throw "Error writing to socket";
    }
    if (n == 0) {
        throw "Server disconnected";
    }
}
