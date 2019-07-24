//
// Created by emanuele on 24/07/19.
//

#include "MainMenuState.h"
#include "../Game.h"

MainMenuState::MainMenuState() : GameState("MainMenu") {

}

void MainMenuState::exitGameState(Game *g) {
    g->setState(GState::ExitGame);
}

void MainMenuState::optionMenuState(Game *g) {
    g->setState(GState::OptionMenu);
}

void MainMenuState::startGameState(Game *g) {
    g->setState(GState::StartGame);
}