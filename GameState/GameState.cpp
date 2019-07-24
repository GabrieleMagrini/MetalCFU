//
// Created by emanuele on 24/07/19.
//

#include "GameState.h"
#include "IllegalStateException.h"

void GameState::gameOverState(Game &g) {
    throw IllegalStateException("Illegal state tarnsiction from " + stateName + " to gameOver state");
}

void GameState::exitGameState(Game &g) {
    throw IllegalStateException("Illegal state tarnsiction from " + stateName + " to exitGame state");
}

void GameState::mainMenuState(Game &g) {
    throw IllegalStateException("Illegal state tarnsiction from " + stateName + " to mainMenu state");
}

void GameState::optionMenuState(Game &g) {
    throw IllegalStateException("Illegal state tarnsiction from " + stateName + " to optionMenu state");
}

void GameState::startGameState(Game &g) {
    throw IllegalStateException("Illegal state tarnsiction from " + stateName + " to startGame state");
}

void GameState::pauseGameState(Game &g) {
    throw IllegalStateException("Illegal state tarnsiction from " + stateName + " to pauseGame state");
}

GameState::GameState(std::string sn) : stateName(std::move(sn)) {}

const std::string &GameState::getStateName() const {
    return stateName;
}

void GameState::setStateName(const std::string &stateName) {
    GameState::stateName = stateName;
}
