
#include <unistd.h>
#include "JoinCommand.h"

void JoinCommand::execute(vector<string> args, int socket) {
    string gameName=args.at(0);
    GamesManager *gamesManager=GamesManager::getInstance();
    int msg,n;

    // see if the name was available and the func succeeded
    if (gamesManager->joinGame(gameName,socket)== false){
        msg=FAIL;
        n=write(socket,&msg,sizeof(msg));
        // doesn't matter if the write was successful, we do the same
        close(socket);
    }
}
