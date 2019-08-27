//
// Created by emanuele on 24/07/19.
//

#include "GameOverState.h"
#include "../Game.h"

GameOverState::GameOverState() : GameState("GameOver") {

}

void GameOverState::exitGameState(Game &g) {
    g.setState(GState::ExitGame);
}

void GameOverState::mainMenuState(Game &g) {
    g.setState(GState::MainMenu);
}
