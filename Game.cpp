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
#include "Collision.h"


Game::Game(const shared_ptr<sf::RenderWindow> &rw, const sf::Font &font)
        : gameState(new MainMenuState()), renderWin(rw), font(font),
          mainMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          opMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          pauseMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          blocks(map.createMap(std::ifstream("Sources/Maps/mappa.txt"))),
          player(3, nullptr, 100, 20, 100, 10) {
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

    bool dKeyPressed = false;
    bool aKeyPressed = false;
    while (renderWin->isOpen()) {
        sf::Event event;
        if (gameState->getStateName() == "MainMenu") {    //MainMenu loop

            while (renderWin->pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    exitGameState();

                if (event.type == sf::Event::MouseButtonReleased) {
                    if (mainMenu.isOptionButtonPressed()) {
                        optionMenuState();

                    } else if (mainMenu.isExitButtonPressed()) {
                        exitGameState();
                    } else if (mainMenu.isStartButtonPressed()) {
                        startGameState();
                    }
                }

                mainMenu.update();

            }

            mainMenu.render();

        } else if (gameState->getStateName() == "OptionMenu") {   //OptionMenu loop
            while (renderWin->pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    renderWin->close();

                if (event.type == sf::Event::MouseButtonReleased) {
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
                        stringstream ss;
                        ss << renderWin->getSize().x << "x" << renderWin->getSize().y;
                        if (resolution != ss.str()) {
                            //renderWin= std::shared_ptr<sf::RenderWindow>(new sf::RenderWindow(sf::VideoMode(opMenu.getRes().x, opMenu.getResolution().y),"Metal CFU"));
                            renderWin->setSize(opMenu.getResolution());
                        }
                        if (!volume) {
                            //TODO
                        }
                        ss.str("");
                        mainMenuState();
                    }
                }

                opMenu.update();
            }

            opMenu.render();

        } else if (gameState->getStateName() == "StartGame") {      // Game loop

            while (renderWin->pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    renderWin->close();

                if (event.type == sf::Event::MouseButtonReleased) {}

                if (event.type == sf::Event::KeyPressed) {

                    sf::Texture texture;
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:

                            texture.create(renderWin->getSize().x, renderWin->getSize().y);
                            texture.update(*renderWin);
                            pauseMenu.setTextureBackGround(texture);
                            pauseGameState();
                            break;
                        case sf::Keyboard::D:
                            dKeyPressed = true;
                            break;
                        case sf::Keyboard::A:
                            aKeyPressed = true;
                            break;

                    }


                } else if (event.type == sf::Event::KeyReleased) {
                    switch (event.key.code) {
                        case sf::Keyboard::D:
                            dKeyPressed = false;
                            break;
                        case sf::Keyboard::A:
                            aKeyPressed = false;
                            break;
                    }
                }
            }

            //UPDATE
            if (dKeyPressed) {
                player.walk(1);
            } else if (aKeyPressed) {
                player.walk(3);
            }

            //Adding gravity to the player

            for (auto sprite : blocks) {
                sprite.checkCollision(&player);
            }
            map.gravityApply(-10, &player, nullptr);


            //RENDER
            renderMap();
            renderWin->draw(player);
            renderWin->display();


        } else if (gameState->getStateName() == "PauseGame") {      //pause menu
            while (renderWin->pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    renderWin->close();


                if (event.type == sf::Event::MouseButtonReleased) {
                    if (pauseMenu.isBackGameButtonPressed()) {
                        startGameState();
                    } else if (pauseMenu.isMainMenuButtonPressed()) {
                        mainMenuState();
                    }
                }
                pauseMenu.update();
            }
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
        //sprite.setOrigin(100, -310);
        renderWin->draw(sprite);
    }

}
