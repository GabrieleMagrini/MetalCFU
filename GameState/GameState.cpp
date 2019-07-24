//
// Created by emanuele on 24/07/19.
//

#include "GameState.h"
#include "IllegalStateException.h"

void GameState::gameOverState() {
    throw IllegalStateException("Illegal state tarnsiction");
}

void GameState::exitGameState() {
    throw IllegalStateException("Illegal state tarnsiction");
}

void GameState::mainMenuState() {
    throw IllegalStateException("Illegal state tarnsiction");
}

void GameState::OptionState() {
    throw IllegalStateException("Illegal state tarnsiction");
}

void GameState::startGameState() {
    throw IllegalStateException("Illegal state tarnsiction");
}

void GameState::pauseGameState() {
    throw IllegalStateException("Illegal state tarnsiction");
}