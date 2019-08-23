//
// Created by emanuele on 25/07/19.
//

#ifndef METALCFU_PAUSEGAMESTATE_H
#define METALCFU_PAUSEGAMESTATE_H

#include "GameState.h"

class Game;

class PauseGameState : public GameState {
public:
    PauseGameState();

    void mainMenuState(Game &g) override;

    void startGameState(Game &g) override;
};


#endif //METALCFU_PAUSEGAMESTATE_H
