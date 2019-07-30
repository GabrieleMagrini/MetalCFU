//
// Created by emanuele on 24/07/19.
//

#include "Game.h"
#include "GameState/MainMenuState.h"
#include "GameState/GameOverState.h"
#include "GameState/OptionMenuState.h"
#include "GameState/StartGameState.h"
#include "GameState/PauseGameState.h"
#include "GameState/ExitGameState.h"


Game::Game(const shared_ptr<sf::RenderWindow> &rw, const sf::Font &font)
        : gameState(new MainMenuState()), renderWin(rw), font(font),
          mainMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          opMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font) {
    (*renderWin).setFramerateLimit(30);
    (*renderWin).setKeyRepeatEnabled(false);
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

void Game::gameOverState() {
    gameState->gameOverState(this);
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

        case GState::StartGame:
            gameState = std::unique_ptr<GameState>(new StartGameState());
            break;

        case GState::PauseGame:
            gameState = std::unique_ptr<GameState>(new PauseGameState());
            break;


        case GState::ExitGame:
            gameState = std::unique_ptr<GameState>(new ExitGameState());
    }
}

void Game::loop() {

    while ((*renderWin).isOpen()) {


        sf::Event event;
        while ((*renderWin).pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                (*renderWin).close();

        }


        if ((*gameState).getStateName() == "MainMenu") {

            if (mainMenu.isOptionButtonPressed()) {
                optionMenuState();

            }
            if (mainMenu.isExitButtonPressed()) {
                (*renderWin).close();
            }


            mainMenu.update();
            mainMenu.render();

        } else if ((*gameState).getStateName() == "OptionMenu") {

            if (opMenu.isVolumeButtonPressed()) {
                opMenu.volumeButtonUpdate(true);
            } else if (opMenu.isResButtonPressed()) {
                opMenu.resButtonUpdate(true);
            } else if (opMenu.isCancelButtonPressed()) {
                mainMenuState();
            }

            opMenu.update();
            opMenu.render();

        }


    }
}