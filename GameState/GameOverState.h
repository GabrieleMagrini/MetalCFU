//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAMEOVERSTATE_H
#define METALCFU_GAMEOVERSTATE_H

#include "GameState.h"

class Game;

class GameOverState : public GameState {
public:
    GameOverState();

    void exitGameState(Game &g) override;

    void mainMenuState(Game &g) override;
};


#endif //METALCFU_GAMEOVERSTATE_H
