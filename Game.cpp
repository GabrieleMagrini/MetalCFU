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
    while (renderWin->isOpen()) {


        sf::Event event;
        while (renderWin->pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                renderWin->close();

            if (event.type == sf::Event::MouseButtonReleased)
                update();

            if (event.type == sf::Event::KeyPressed) {
                update();
            }
        }
        render();

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

/***
 * function that render all things.
 */
void Game::render() {
    if (gameState->getStateName() == "MainMenu") {    //MainMenu loop
        mainMenu.update();
        mainMenu.render();

    } else if (gameState->getStateName() == "OptionMenu") {   //OptionMenu loop
        opMenu.update();
        opMenu.render();

    } else if (gameState->getStateName() == "StartGame") {      //start Game
        renderMap();

    } else if (gameState->getStateName() == "PauseGame") {      //pause menu

        pauseMenu.update();
        pauseMenu.render();

    } else if (gameState->getStateName() == "ExitGame") {  // exit game
        renderWin->close();

    }
}

/***
 *  updates all objects that can be interacted with the user
 */
void Game::update() {


    if (gameState->getStateName() == "MainMenu") {    //MainMenu loop

        if (mainMenu.isOptionButtonPressed()) {
            optionMenuState();

        } else if (mainMenu.isExitButtonPressed()) {
            exitGameState();
        } else if (mainMenu.isStartButtonPressed()) {
            startGameState();
        }
    } else if (gameState->getStateName() == "OptionMenu") {   //OptionMenu loop


        if (opMenu.isVolumeButtonPressed()) {
            opMenu.volumeButtonUpdate();
        } else if (opMenu.isResButtonPressed()) {
            opMenu.resButtonUpdate();
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

    } else if (gameState->getStateName() == "StartGame") {      //start Game

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            if (gameState->getStateName() == "StartGame") {


                sf::Texture texture;

                texture.create(renderWin->getSize().x, renderWin->getSize().y);
                texture.update(*renderWin);
                pauseMenu.setTextureBackGround(texture);
                pauseGameState();

            }
        }

        renderMap();

    } else if (gameState->getStateName() == "PauseGame") {      //pause menu

        if (pauseMenu.isBackGameButtonPressed())
            startGameState();
        else if (pauseMenu.isMainMenuButtonPressed())
            mainMenuState();
    } else if (gameState->getStateName() == "ExitGame") {  // exit game
        renderWin->close();

    }

}