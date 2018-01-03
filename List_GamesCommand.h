

#ifndef SERVER_LIST_GAMESCOMMAND_H
#define SERVER_LIST_GAMESCOMMAND_H

#include "Command.h"

class List_GamesCommand: public Command {
public:
    virtual void execute(vector<string> args,int socket=0);

private:
    void sendName(string &name,int socket);
};


#endif //SERVER_LIST_GAMESCOMMAND_H
