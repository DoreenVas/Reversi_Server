
#include <unistd.h>
#include "Close_ServerCommand.h"

void Close_ServerCommand::execute(vector<string> args, int socket) {
    close(socket);
    GamesManager *gameManager=GamesManager::getInstance();
    gameManager->closeAllGames();
    delete gameManager;
}
