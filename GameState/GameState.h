//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAMESTATE_H
#define METALCFU_GAMESTATE_H


#include "IllegalStateException.h"

class GameState {
public:
    GameState();

    virtual ~GameState() = default;

    virtual void gameOverState();

    virtual void exitGameState();

    virtual void mainMenuState();

    virtual void OptionState();

    virtual void startGameState();

    virtual void pauseGameState();

private:
    IllegalStateException ex;
};


#endif //METALCFU_GAMESTATE_H
