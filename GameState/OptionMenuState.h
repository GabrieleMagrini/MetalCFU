//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_OPTIONMENUSTATE_H
#define METALCFU_OPTIONMENUSTATE_H

#include "GameState.h"

class Game;

class OptionMenuState : public GameState {
public:
    OptionMenuState();

    void mainMenuState(Game *g) override;
};


#endif //METALCFU_OPTIONMENUSTATE_H
