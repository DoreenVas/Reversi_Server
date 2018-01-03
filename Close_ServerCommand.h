
#ifndef SERVER_CLOSE_SERVERCOMMAND_H
#define SERVER_CLOSE_SERVERCOMMAND_H

#include "Command.h"

/*****************************************************************************************************
* class name: Close_ServerCommand
* description: in charge of the Close_Server command
******************************************************************************************************/
class Close_ServerCommand : public Command {
public:
/***************************************************************************************
* function name: execute
* the input: vector of arguments and a socket
* the output: none
* the function operation: activates GamesManager function closeAllGames,closes the received
* socket(will be the server socket), then deletes the gameManager instance.
****************************************************************************************/
    virtual void execute(vector<string> args,int socket=0);
};


#endif //SERVER_CLOSE_SERVERCOMMAND_H
