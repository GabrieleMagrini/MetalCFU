//
// Created by emanuele on 24/07/19.
//

#include "StartGameState.h"
#include "../Game.h"

StartGameState::StartGameState() : GameState("StartGame") {

}

void StartGameState::pauseGameState(Game &g) {
    g.setState(GState::PauseGame);
}

void StartGameState::gameOverState(Game &g) {
    g.setState(GState::GameOver);
}
