//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAME_H
#define METALCFU_GAME_H

#include <memory>

#include "Map.h"
#include "GameState/GameState.h"

enum class GState {
    GameOver, ExitGame, MainMenu, OptionMenu, StartGame, PauseGame
};

class Game {
public:
    explicit Game(Player p, Map m = Map());

    void setState(GState state);

private:

    Map map;
    Player player;
    std::vector<Enemy> enemies;
    std::unique_ptr<GameState> gameState;
    //TODO
};


#endif //METALCFU_GAME_H