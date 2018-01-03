
#include <pthread.h>
#include "GamesManager.h"

GamesManager* GamesManager::instance=0;
pthread_mutex_t GamesManager::lockMap;
pthread_mutex_t GamesManager::lockInstance;
static void *startGame(void *);

GamesManager* GamesManager::getInstance() {
    if (instance == 0){
        pthread_mutex_lock(&lockInstance);
        if (instance == 0 ){
            instance=new GamesManager();
        }
        pthread_mutex_unlock(&lockInstance);
    }
    return instance;
}

GamesManager::GamesManager() {}

bool GamesManager::addNewGame(string gameName, Game *game) {
    pthread_mutex_lock(&lockMap);
    if(gamesMap.find(gameName)== gamesMap.end()) {
        gamesMap[gameName]=game;
        pthread_mutex_unlock(&lockMap);
        return true;
    }
    else{
        pthread_mutex_unlock(&lockMap);
        return false;
    }
}

vector<string> GamesManager::getListOfActiveGames() {
    vector <string> names;
    pthread_mutex_lock(&lockMap);
    map<string,Game *>::iterator it;
    for(it=gamesMap.begin();it!=gamesMap.end();it++) {
        if (it->second->getPlayersStatus()==ONE_PLAYER){
            names.push_back(it->first);
        }
    }
    pthread_mutex_unlock(&lockMap);
    return names;
}

bool GamesManager::joinGame(string gameName, int socket) {
    pthread_t  thread;
    pthread_mutex_lock(&lockMap);
    map<string,Game *>::iterator it;
    for(it=gamesMap.begin();it!=gamesMap.end();it++) {
        if (it->first.compare(gameName)==0){
            if(it->second->getPlayersStatus()==ONE_PLAYER){
                it->second->addSecondPlayer(socket);
                pthread_create(&thread,NULL,&startGame,(void *)it->second);
                pthread_mutex_unlock(&lockMap);
                return true;
            }
            else{
                pthread_mutex_unlock(&lockMap);
                return false;
            }
        }
    }
    pthread_mutex_unlock(&lockMap);
    return false;
}

void GamesManager::deleteGame(string gameName,Game *game) {
    pthread_mutex_lock(&lockMap);
    gamesMap.erase(gameName);
    pthread_mutex_unlock(&lockMap);
    delete game;
}

void GamesManager::closeAllGames() {
    map<string, Game *>::iterator it;
    for (it = gamesMap.begin(); it != gamesMap.end(); it++) {
        it->second->serverStopMsg();
        it->second->endGame();
    }
}

static void *startGame(void *game1) {
    Game *game=(Game *)game1;
    game->play();
}
