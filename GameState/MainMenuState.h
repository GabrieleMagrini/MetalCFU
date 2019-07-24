//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_MAINMENUSTATE_H
#define METALCFU_MAINMENUSTATE_H

#include "GameState.h"

class MainMenuState : public GameState {
public:
    explicit MainMenuState(std::string ns);

    void exitGameState() override;

    void optionMenuState() override;

    void startGameState() override;


};


#endif //METALCFU_MAINMENUSTATE_H
