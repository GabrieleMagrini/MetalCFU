//
// Created by emanuele on 25/07/19.
//

#include "PauseGameState.h"
#include "../Game.h"

PauseGameState::PauseGameState() : GameState("PauseGame") {

}

void PauseGameState::mainMenuState(Game &g) {
    g.setState(GState::MainMenu);
}

void PauseGameState::startGameState(Game &g) {
    g.setState(GState::StartGame);
}
