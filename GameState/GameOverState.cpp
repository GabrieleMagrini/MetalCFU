//
// Created by emanuele on 24/07/19.
//

#include "GameOverState.h"

GameOverState::GameOverState(std::string desc) : GameState(std::move(desc)) {

}

void GameOverState::exitGameState(Game &g) {
    g.setState(GState::ExitGame);
}
