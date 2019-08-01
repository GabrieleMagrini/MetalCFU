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
          opMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          pauseMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          blocks(map.createMap(std::ifstream("Sources/Maps/mappa.txt"))) {
    renderWin->setFramerateLimit(30);
    renderWin->setKeyRepeatEnabled(false);
    textBackGround.loadFromFile("Sources/Pngs/wallpaper_1.jpeg");
    backGround.setTexture(textBackGround);
    backGround.setPosition(0, 0);
    float scalex = static_cast<float>(renderWin->getSize().x) / static_cast<float>(textBackGround.getSize().x);
    float scaley = static_cast<float>(renderWin->getSize().y) / static_cast<float>(textBackGround.getSize().y);

    backGround.setScale(scalex, scaley);
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

/***
 * Game loop and state pattern work through this method
 */
void Game::loop() {
    bool action = true;  //one action to one single button pressed in GUI state
    while (renderWin->isOpen()) {


        sf::Event event;
        while (renderWin->pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                exitGameState();

            if (event.type == sf::Event::MouseButtonReleased)
                action = true;

            if (event.type == sf::Event::KeyReleased) {
                action = true;
            }
        }

        if (gameState->getStateName() == "MainMenu") {    //MainMenu loop
            if (action) {
                if (mainMenu.isOptionButtonPressed()) {
                    optionMenuState();

                } else if (mainMenu.isExitButtonPressed()) {
                    exitGameState();
                } else if (mainMenu.isStartButtonPressed()) {
                    startGameState();
                }
                action = false;
            }
            mainMenu.update();
            mainMenu.render();


        } else if (gameState->getStateName() == "OptionMenu") {   //OptionMenu loop

            if (action) {
                if (opMenu.isVolumeButtonPressed()) {
                    opMenu.volumeButtonUpdate(action);
                } else if (opMenu.isResButtonPressed()) {
                    opMenu.resButtonUpdate(action);
                } else if (opMenu.isCancelButtonPressed()) {
                    opMenu.cancelButtonUpdate();
                    mainMenuState();
                } else if (opMenu.isSaveButtonPressed()) {
                    std::string resolution;
                    bool volume;
                    opMenu.saveButtonUpdate(resolution, volume);
                    if (resolution != renderWin->getSize().x + "x" + renderWin->getSize().y) {
                        //renderWin= std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(opMenu.getRes().x, opMenu.getResolution().y),"Metal CFU"));
                        renderWin->setSize(opMenu.getResolution());
                    }
                    if (!volume) {
                        //TODO
                    }
                    mainMenuState();
                }
                action = false;
            }
            opMenu.update();
            opMenu.render();

        } else if (gameState->getStateName() == "StartGame") {      //start Game

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                if (gameState->getStateName() == "StartGame") {
                    pauseGameState();
                    action = false;
                }
            }

            renderMap();

        } else if (gameState->getStateName() == "PauseGame") {      //pause menu
            sf::Image image = renderWin->capture();

            sf::Texture texture;
            texture.loadFromImage(image);
            pauseMenu.setTextureBackGround(texture);

            if (action) {
                if (pauseMenu.isBackGameButtonPressed())
                    startGameState();
                else if (pauseMenu.isMainMenuButtonPressed())
                    mainMenuState();
                action = false;
            }

            pauseMenu.update();
            pauseMenu.render();
        } else if (gameState->getStateName() == "ExitGame") {  // exit game
            renderWin->close();
        }

    }
}

/*****
 * function that render the map of the game.
 */
void Game::renderMap() {
    renderWin->draw(backGround);
    for (auto &sprite : blocks) {
        sprite.setOrigin(100, -310);
        renderWin->draw(sprite);
    }
    renderWin->display();
}