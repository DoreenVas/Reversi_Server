

#ifndef SERVER_LIST_GAMESCOMMAND_H
#define SERVER_LIST_GAMESCOMMAND_H

#include "Command.h"

/*****************************************************************************************************
* class name: List_GamesCommand
* description: in charge of the List_Games command
******************************************************************************************************/
class List_GamesCommand: public Command {
public:
/***************************************************************************************
* function name: execute
* the input: vector of arguments and a socket of a client
* the output: none
* the function operation: gets the list of active games from GamesManager and sends them
 * to the client, each name with the sendName function.
****************************************************************************************/
    virtual void execute(vector<string> args,int socket=0);

private:
/***************************************************************************************
* function name: sendName
* the input: string of name and client socket
* the output: none
* the function operation: writes the name of game to the client socket.
****************************************************************************************/
    void sendName(string &name,int socket);
};


#endif //SERVER_LIST_GAMESCOMMAND_H
