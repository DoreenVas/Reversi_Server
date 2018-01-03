

#include <unistd.h>
#include "StartCommand.h"

void StartCommand::execute(vector<string> args, int socket) {
    string gameName=args.at(0);
    GamesManager *gamesManager=GamesManager::getInstance();
    Game *game =new Game(socket,gameName);
    int msg,n;

    // see if the name was available and the func succeeded
    if (gamesManager->addNewGame(gameName,game)== false){
        msg=FAIL;
        write(socket,&msg,sizeof(msg));
        // doesn't matter if the write was successful, we do the same
        cout << "Client disconnected" << endl;
        close(socket);
        delete game;
    }
    // the game was successfully created
    else{
        msg=SUCCESS;
        n=write(socket,&msg,sizeof(msg));
        if(game->writeCheck(n)== false){
            close(socket);
            cout << "Client disconnected" << endl;
            gamesManager->deleteGame(gameName,game);
        }
    }
}
