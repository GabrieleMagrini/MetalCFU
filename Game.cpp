//
// Created by emanuele on 24/07/19.
//

#include "Game.h"


Game::Game(const shared_ptr<sf::RenderWindow> &rw, const sf::Font &font)
        : gameState(new MainMenuState()), renderWin(rw), font(font),
          mainMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          opMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          pauseMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          player(3, nullptr, 100, 20),
          playerView(sf::FloatRect(renderWin->getPosition().x, renderWin->getPosition().y, renderWin->getSize().x,
                                   renderWin->getSize().y)),
          playerAnimation("Sources/Pngs/player textures/playerTexture.bmp") {
    renderWin->setFramerateLimit(30);
    renderWin->setKeyRepeatEnabled(false);
    textBackGround.loadFromFile("Sources/Pngs/wallpaper_1.jpeg");
    backGround.setTexture(textBackGround);
    backGround.setPosition(0, 0);
    float scaleX = static_cast<float>((renderWin->getSize().x) / static_cast<float>(textBackGround.getSize().x));
    float scaleY = static_cast<float>((renderWin->getSize().y) / static_cast<float>(textBackGround.getSize().y));

    backGround.setScale(scaleX, scaleY);
    //backGround.setOrigin(backGround.getLocalBounds().width / 2, backGround.getLocalBounds().height / 2);

    player.setOrigin(player.getLocalBounds().width / 2, 0);
    playerAnimation.getTexture(player, 0);
    map.setGravity(-10);
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
    bool spaceKeyPressed = false;
    bool shoot = false;
    float startY = 0; //used for jump
    sf::Clock clock;
    int countTexture = 0;

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
                        blocks = map.createMap(std::ifstream("Sources/Maps/mappa.txt"));

                        float scaleX = static_cast<float>(blocks.back().getPosition().x) /
                                       static_cast<float>(textBackGround.getSize().x);
                        float scaleY = static_cast<float>(blocks.back().getPosition().y) /
                                       static_cast<float>(textBackGround.getSize().y);
                        backGround.setPosition(-500, -100);
                        backGround.setScale(scaleX + 1, scaleY + 1);

                        player.setPosition(blocks[1].getPosition().x + 100, 400);

                        clock.restart();
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

                if (event.type == sf::Event::MouseButtonReleased) {
                    switch (event.mouseButton.button) {
                        case sf::Mouse::Left :
                            shoot = false;
                            break;
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed) {
                    switch (event.mouseButton.button) {
                        case sf::Mouse::Left :
                            if (!shoot) {
                                shoot = true;
                                int xMouse = renderWin->getView().getCenter().x - (renderWin->getSize().x / 2) +
                                             (sf::Mouse::getPosition(*renderWin).x);
                                int yMouse = renderWin->getView().getCenter().y - (renderWin->getSize().y / 2) +
                                             sf::Mouse::getPosition(*renderWin).y;
                                Vector2f Fin(xMouse, yMouse);
                            }
                            break;
                    }
                }
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

                        case sf::Keyboard::Space:
                            if (player.isCollisionDown()) {
                                countTexture = 2;
                                startY = player.getPosition().y;
                                player.setJumping(true);
                                spaceKeyPressed = true;
                            }
                            break;

                        default:
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
                        case sf::Keyboard::Space:
                            player.setJumping(false);
                            spaceKeyPressed = false;
                        default:
                            break;
                    }
                }
            }

            //UPDATE
            if (dKeyPressed && !player.isCollisionRight()) {
                player.walk(1);

            } else if (aKeyPressed && !player.isCollisionLeft()) {
                player.walk(3);
            }
            if (spaceKeyPressed) {
                player.jump(100, startY);
                if (player.isJumping())
                    player.walk(0);

            }

            if (clock.getElapsedTime().asSeconds() > 0.15f) {
                if (!player.isJumping())
                    countTexture++;

                if (countTexture == 8)
                    countTexture = 0;
                if (dKeyPressed && !player.isCollisionRight()) {
                    playerAnimation.getTexture(player, countTexture, "right");
                } else if (aKeyPressed && !player.isCollisionLeft()) {
                    playerAnimation.getTexture(player, countTexture, "left");
                }


                clock.restart();
            }

            //Adding gravity to the player
            player.setCollisionDown(false);
            player.setCollisionUp(false);
            player.setCollisionRight(false);
            player.setCollisionLeft(false);
            for (auto sprite : blocks) {
                sprite.checkCollision(player);
            }
            if (!player.isJumping())
                map.gravityApply(player);


            playerView.setCenter(player.getPosition());
            //RENDER
            renderWin->clear();
            renderMap();
            renderWin->draw(player);
            renderWin->setView(playerView);
            renderWin->display();


        } else if (gameState->getStateName() == "PauseGame") {      //pause menu
            playerView.setCenter(renderWin->getSize().x / 2.0f, renderWin->getSize().y / 2.0f);
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
            renderWin->setView(playerView);
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
    //backGround.setPosition(playerView.getCenter());
    renderWin->draw(backGround);
    for (auto &sprite : blocks) {
        renderWin->draw(sprite);
    }

}
