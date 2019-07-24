//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_MAINMENUSTATE_H
#define METALCFU_MAINMENUSTATE_H

#include "GameState.h"
#include "../Game.h"

class MainMenuState : public GameState {
public:
    explicit MainMenuState(std::string ns);

    void exitGameState(Game &g) override;

    void optionMenuState(Game &g) override;

    void startGameState(Game &g) override;


};


#endif //METALCFU_MAINMENUSTATE_H
