
#ifndef SERVER_GAMESMANAGER_H
#define SERVER_GAMESMANAGER_H

#include <map>
#include <vector>
#include "Game.h"

class GamesManager {
public:
    GamesManager(GamesManager *instance);
    static GamesManager *getInstance();
    bool addNewGame(string gameName,Game *game);
    void deleteGame(string gameName,Game *game);
    bool joinGame(string gameName,int socket);
    void closeAllGames();
    vector <string> getListOfActiveGames();
    Game* getGameByName(string nameGame);

private:
    //A singleton
    GamesManager();
    GamesManager(const GamesManager &);
    static GamesManager* instance;
    static pthread_mutex_t lockMap;
    static pthread_mutex_t lockInstance;
    map <string,Game *> gamesMap;
};


#endif //SERVER_GAMESMANAGER_H
