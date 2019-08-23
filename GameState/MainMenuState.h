//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_MAINMENUSTATE_H
#define METALCFU_MAINMENUSTATE_H

#include "GameState.h"

class Game;

class MainMenuState : public GameState {
public:
    MainMenuState();

    void exitGameState(Game &g) override;

    void optionMenuState(Game &g) override;

    void startGameState(Game &g) override;


};


#endif //METALCFU_MAINMENUSTATE_H
