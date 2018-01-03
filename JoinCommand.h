
#ifndef SERVER_JOINCOMMAND_H
#define SERVER_JOINCOMMAND_H

#include "Command.h"

/*****************************************************************************************************
* class name: JoinCommand
* description: in charge of the join command
******************************************************************************************************/
class JoinCommand: public Command {
public:
/***************************************************************************************
* function name: execute
* the input: vector of arguments and a socket of a client
* the output: none
* the function operation: checks if gamesManager function joinGame was successful, if so
* the play function begins.also informes the clients with message.
****************************************************************************************/
    virtual void execute(vector<string> args,int socket=0);
};


#endif //SERVER_JOINCOMMAND_H
