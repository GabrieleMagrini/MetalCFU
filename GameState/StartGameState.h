//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_STARTGAMESTATE_H
#define METALCFU_STARTGAMESTATE_H

#include "GameState.h"

class Game;

class StartGameState : public GameState {
public:
    StartGameState();

    void pauseGameState(Game *g) override;
};


#endif //METALCFU_STARTGAMESTATE_H
