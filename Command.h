
#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H
#define FAIL -1
#define SUCCESS 0

#include <vector>
#include <string>
#include "Game.h"
#include "GamesManager.h"

using namespace std;

/*****************************************************************************************************
* Interface name: Command
* description: in charge of executing commands
******************************************************************************************************/
class Command {
public:
/***************************************************************************************
* function name: execute (virtual)
* the input: vector of arguments and a socket of a client
* the output: none
* the function operation: to execute each command in the right class
****************************************************************************************/
    virtual void execute(vector<string> args,int socket=0)=0;
/***************************************************************************************
* destructor name: ~Command
* the input: none
* the output: none
* the function operation:executed in every inheriting class
****************************************************************************************/
    virtual ~Command() {}
};


#endif //SERVER_COMMAND_H
