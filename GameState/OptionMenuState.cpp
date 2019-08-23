//
// Created by emanuele on 24/07/19.
//

#include "OptionMenuState.h"
#include "../Game.h"

OptionMenuState::OptionMenuState() : GameState("OptionMenu") {

}

void OptionMenuState::mainMenuState(Game &g) {
    g.setState(GState::MainMenu);
}
