

#ifndef SERVER_STARTCOMMAND_H
#define SERVER_STARTCOMMAND_H

#include "Command.h"

/*****************************************************************************************************
* class name: StartCommand
* description: in charge of the start command
******************************************************************************************************/
class StartCommand: public Command {
public:
/***************************************************************************************
* function name: execute
* the input: vector of arguments and a socket of a client
* the output: none
* the function operation: checks if gamesManager function addNewGame was successful and
* informs the client with message accordingly.
****************************************************************************************/
    virtual void execute(vector<string> args,int socket=0);
};


#endif //SERVER_STARTCOMMAND_H
