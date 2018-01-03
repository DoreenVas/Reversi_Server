
#include "CommandsManager.h"
#include "StartCommand.h"
#include "List_GamesCommand.h"
#include "JoinCommand.h"
#include "Close_ServerCommand.h"


CommandsManager* CommandsManager::instance=0;
pthread_mutex_t CommandsManager::lock;

CommandsManager* CommandsManager::getInstance() {
    if (instance == 0){
        pthread_mutex_lock(&lock);
        if (instance == 0 ){
            instance=new CommandsManager();
        }
        pthread_mutex_unlock(&lock);
    }
    return instance;
}

CommandsManager::CommandsManager() {
    commandsMap["start"]=new StartCommand();
    commandsMap["list_games"]=new List_GamesCommand();
    commandsMap["join"]=new JoinCommand();
    commandsMap["close_server"]=new Close_ServerCommand();
}

void CommandsManager::executeCommand(string command, vector<string> args, int socket) {
    Command *commandObj=commandsMap[command];
    commandObj->execute(args,socket);
}

CommandsManager::~CommandsManager() {
    map<string,Command *>::iterator it;
    for(it=commandsMap.begin();it!=commandsMap.end();it++) {
        delete it->second;
    }
}

