
#ifndef SERVER_CLOSE_SERVERCOMMAND_H
#define SERVER_CLOSE_SERVERCOMMAND_H

#include "Command.h"

class Close_ServerCommand : public Command {
public:
    virtual void execute(vector<string> args,int socket=0);
};


#endif //SERVER_CLOSE_SERVERCOMMAND_H
