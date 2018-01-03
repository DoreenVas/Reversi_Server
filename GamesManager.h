
#ifndef SERVER_GAMESMANAGER_H
#define SERVER_GAMESMANAGER_H

#include <map>
#include <vector>
#include "Game.h"

/*****************************************************************************************************
* class name: GamesManager
* description: in charge of game rooms
******************************************************************************************************/
class GamesManager {
public:
/***************************************************************************************
* function name: getInstance
* the input: none
* the output: GamesManager pointer instance
* the function operation: returns the only instance (singleton) if not existing creates one.
****************************************************************************************/
    static GamesManager *getInstance();
/***************************************************************************************
* function name: addNewGame
* the input: string gameName,Game *game
* the output: bool , true if the game was added successfully ,otherwise false
* the function operation:adds the game name and pointer to the map if the name wasn't already there.
****************************************************************************************/
    bool addNewGame(string gameName,Game *game);
/***************************************************************************************
* function name: deleteGame
* the input: string gameName,Game *game
* the output: none
* the function operation: removes the correct game from the map. then deletes it.
****************************************************************************************/
    void deleteGame(string gameName,Game *game);
/***************************************************************************************
* function name: joinGame
* the input: string gameName,int socket
* the output: true if the game was joined otherwise false
* the function operation: if a room with matching name and one player exists the room is joined
* by the addSecondPlayer function.
****************************************************************************************/
    bool joinGame(string gameName,int socket);
/***************************************************************************************
* function name: getListOfActiveGames
* the input: none
* the output: vector of available games names
* the function operation: pushes all the one player games names to a vector and returns it
****************************************************************************************/
    vector <string> getListOfActiveGames();
/***************************************************************************************
* function name: getGameByName
* the input: string nameGame
* the output: Game*
* the function operation: returns a pointer to the game with the received name
****************************************************************************************/
    Game* getGameByName(string nameGame);
/***************************************************************************************
* function name: closeAllGames
* the input: none
* the output: none
* the function operation: calls for each game to the Game functions serverStopMsg and endGame
****************************************************************************************/
    void closeAllGames();

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
