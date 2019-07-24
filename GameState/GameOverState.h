//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAMEOVERSTATE_H
#define METALCFU_GAMEOVERSTATE_H

#include "GameState.h"

class GameOverState : public GameState {
public:
    explicit GameOverState(std::string desc);

    void exitGameState(Game &g) override;
};


#endif //METALCFU_GAMEOVERSTATE_H
