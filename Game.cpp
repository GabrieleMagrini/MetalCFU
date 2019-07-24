//
// Created by emanuele on 24/07/19.
//

#include "Game.h"
#include "GameState/MainMenuState.h"
#include "GameState/GameOverState.h"
#include "GameState/OptionMenuState.h"

void Game::gameOverState() {
}

Game::Game() : gameState(new MainMenuState()) {

}

void Game::exitGameState() {
    gameState->exitGameState(this);
}

void Game::mainMenuState() {
    gameState->mainMenuState(this);
}

void Game::optionMenuState() {
    gameState->optionMenuState(this);
}

void Game::startGameState() {
    gameState->startGameState(this);
}

void Game::pauseGameState() {
    gameState->pauseGameState(this);
}

void Game::setState(GState state) {
    switch (state) {
        case GState::GameOver:
            gameState = std::unique_ptr<GameState>(new GameOverState());
            break;

        case GState::MainMenu:
            gameState = std::unique_ptr<GameState>(new MainMenuState());
            break;

        case GState::OptionMenu:
            gameState = std::unique_ptr<GameState>(new OptionMenuState());
            break;
    }
}
