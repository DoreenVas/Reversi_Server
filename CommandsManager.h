
#ifndef SERVER_COMMANDSMANAGER_H
#define SERVER_COMMANDSMANAGER_H

#include <map>
#include "Command.h"

/*****************************************************************************************************
* class name: CommandsManager
* description: in charge of commands
******************************************************************************************************/
class CommandsManager {
public:
/***************************************************************************************
* function name: getInstance
* the input: none
* the output: CommandsManager pointer instance
* the function operation: returns the only instance (singleton) if not existing creates one.
****************************************************************************************/
    static CommandsManager *getInstance();
/***************************************************************************************
* function name: executeCommand
* the input: command string, vector of arguments and client socket
* the output: none
* the function operation: calls the correct execute function by the command string
****************************************************************************************/
    void executeCommand(string command, vector<string> args,int socket=0);
/***************************************************************************************
* destructor name: ~CommandsManager
* the input: none
* the output: none
* the function operation: deletes the commands classes objects
****************************************************************************************/
    ~CommandsManager();
private:
/***************************************************************************************
* constructor name: CommandsManager
* the input: none
* the output: none
* the function operation: creates the commands classes objects
****************************************************************************************/
    CommandsManager();
    CommandsManager(const CommandsManager &);
    static CommandsManager* instance;
    static pthread_mutex_t lock;

    map <string,Command *> commandsMap;
};


#endif //SERVER_COMMANDSMANAGER_H
