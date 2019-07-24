//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAME_H
#define METALCFU_GAME_H

#include <memory>

#include "Map.h"

class GameState;

enum class GState {
    GameOver, ExitGame, MainMenu, OptionMenu, StartGame, PauseGame
};

class Game {
public:
    explicit Game();

    virtual ~Game() = default;

    void gameOverState();

    void exitGameState();

    void mainMenuState();

    void optionMenuState();

    void startGameState();

    void pauseGameState();

    void setState(GState state);

private:
    std::unique_ptr<GameState> gameState;
    //TODO
};


#endif //METALCFU_GAME_H