
#include <unistd.h>
#include "JoinCommand.h"
static void *startGame(void *);

void JoinCommand::execute(vector<string> args, int socket) {
    string gameName=args.at(0);
    GamesManager *gamesManager=GamesManager::getInstance();
    int msg;

    // see if the name was available and the func succeeded
    if (gamesManager->joinGame(gameName,socket)== false){
        msg=FAIL;
        write(socket,&msg,sizeof(msg));
        // doesn't matter if the write was successful, we do the same
        close(socket);
        cout << "Client disconnected" << endl;
    }
    else{
        msg=SUCCESS;
        int n=write(socket,&msg,sizeof(msg));
        if (n == -1){
            cout<<"Error writing"<<endl;
            close(socket);
        }
        if (n == 0){
            cout << "Client disconnected" << endl;
            close(socket);
        }
        pthread_t thread;
        Game *game=gamesManager->getGameByName(gameName);
        game->setThread(thread);
        pthread_create(&thread,NULL,&startGame,(void *)game);
    }
}

static void *startGame(void *game1) {
    Game *game=(Game *)game1;
    game->play();
}


