
#ifndef SERVER_COMMAND_H
#define SERVER_COMMAND_H
#define FAIL -1
#define SUCCESS 0

#include <vector>
#include <string>
#include "Game.h"
#include "GamesManager.h"

using namespace std;

class Command {
public:
    virtual void execute(vector<string> args,int socket=0)=0;
    virtual ~Command() {}
};


#endif //SERVER_COMMAND_H
