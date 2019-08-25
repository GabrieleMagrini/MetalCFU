//
// Created by emanuele on 24/07/19.
//

#include "Game.h"


Game::Game(const shared_ptr<sf::RenderWindow> &rw, const sf::Font &font)
        : gameState(new MainMenuState()), renderWin(rw), font(font),
          mainMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          opMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          pauseMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          player(3, weaponFactory.createWeapon(WeaponType::pistol).get(), 100, 20),
          playerView(sf::FloatRect(renderWin->getPosition().x, renderWin->getPosition().y, renderWin->getSize().x,
                                   renderWin->getSize().y)),
          playerAnimation("Sources/Pngs/player textures/playerTexture.bmp"), playerHud(rw, font), event() {
    renderWin->setFramerateLimit(30);
    renderWin->setKeyRepeatEnabled(false);
    textBackGround.loadFromFile("Sources/Pngs/wallpaper_1.jpeg");
    backGround.setTexture(textBackGround);
    backGround.setPosition(0, 0);
    float scaleX = static_cast<float>((renderWin->getSize().x) / static_cast<float>(textBackGround.getSize().x));
    float scaleY = static_cast<float>((renderWin->getSize().y) / static_cast<float>(textBackGround.getSize().y));
    backGround.setScale(scaleX, scaleY);
    player.setOrigin(player.getLocalBounds().width / 2, 0);
    playerAnimation.getTexture(player, 0, 0, "right");
}

void Game::exitGameState() {
    gameState->exitGameState(*this);
}

void Game::mainMenuState() {
    gameState->mainMenuState(*this);
}

void Game::optionMenuState() {
    gameState->optionMenuState(*this);
}

void Game::startGameState() {
    gameState->startGameState(*this);
}

void Game::pauseGameState() {
    gameState->pauseGameState(*this);
}

void Game::gameOverState() {
    gameState->gameOverState(*this);
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
    bool canShoot = false;

    float startY = 0; //used for jump
    sf::Clock animationClock;
    sf::Clock weaponClock;

    std::vector<sf::Clock> enemyShootClock;
    int countTexture = 0;
    int enemyVectorSize = 10;

    float xStart = 0;
    float yStart = 0;
    float xPressed = 0;
    float yPressed = 0;
    vector<Ammo> bullets;
    vector<Ammo> enemyBullets;
    vector<Vector2f> aimI;
    vector<Vector2f> aimF;
    vector<Vector2f> EaimI;
    vector<Vector2f> EaimF;
    vector<vector<Ammo>> Bulletz;

    sf::Texture screenShoot;

    while (renderWin->isOpen()) {
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
                        enemies = std::vector<Enemy>(enemyVectorSize, *enemyFactory.createEnemy(EnemyType::Soldier));
                        for (int j = 0; j <
                                        enemies.size(); j++) {
                            enemies[j] = *enemyFactory.createEnemy(
                                    EnemyType::Soldier);   //Placing the enemies in the map
                            enemies[j].setPosition(blocks[j + 5].getPosition().x + 200 * j, 250);
                            std::vector<Ammo> enemy;
                            Bulletz.push_back(enemy);
                        }

                        float scaleX = static_cast<float>(blocks.back().getPosition().x) /
                                       static_cast<float>(textBackGround.getSize().x);
                        float scaleY = static_cast<float>(blocks.back().getPosition().y) /
                                       static_cast<float>(textBackGround.getSize().y);
                        backGround.setPosition(-500, -100);
                        backGround.setScale(scaleX + 1, scaleY + 1);

                        player = Player(3, weaponFactory.createWeapon(WeaponType::pistol).get(), 100, 20,
                                        static_cast<int>(blocks[1].getPosition().x) + 100, 400);

                        enemyShootClock = vector<sf::Clock>(enemyVectorSize);

                        animationClock.restart();
                        weaponClock.restart();
                        for (auto a  : enemyShootClock) {
                            a.restart();
                        }
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

            float xMouse = renderWin->getView().getCenter().x - (renderWin->getSize().x / 2.0f) +
                           (sf::Mouse::getPosition(*renderWin).x);
            float yMouse = renderWin->getView().getCenter().y - (renderWin->getSize().y / 2.0f) +
                           sf::Mouse::getPosition(*renderWin).y;

            while (renderWin->pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    renderWin->close();
                if (event.type == sf::Event::MouseButtonPressed) {
                    switch (event.mouseButton.button) {                                               //Managing the shoot case through the left mouse button
                        case sf::Mouse::Left :
                            if (canShoot) {
                                xStart = renderWin->getSize().x / 2. + player.getWeapon()->getGlobalBounds().width / 2;
                                yStart = renderWin->getSize().y / 2. +
                                         (player.getWeapon()->getGlobalBounds().height / 2) +
                                         10;
                                xPressed = (sf::Mouse::getPosition(*renderWin).x);
                                yPressed = sf::Mouse::getPosition(*renderWin).y;
                                Vector2f Start(xStart, yStart);
                                aimI.push_back(Start);
                                Vector2f Fin(xPressed, yPressed);
                                aimF.push_back(Fin);

                                if (player.getWeapon()->getCurrentAmmo().size() ||
                                    player.getWeapon()->getName() == "pistol") {
                                    bullets.push_back(player.getWeapon()->shoot());
                                    player.getWeapon()->setShoot(true);
                                }
                                canShoot = false;
                            }

                            break;
                    }
                }
                if (event.type == sf::Event::KeyPressed) {
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            screenShoot.create(renderWin->getSize().x, renderWin->getSize().y);
                            screenShoot.update(*renderWin);
                            pauseMenu.setTextureBackGround(screenShoot);
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
            } else {
                playerAnimation.getTexture(player, 0, xMouse, "right");
                countTexture = 0;
            }
            if (spaceKeyPressed) {
                player.jump(100, startY);
                if (player.isJumping())
                    player.walk(0);
            }

            for (int x = 0; x < enemies.size(); x++) {  //adding behaviour to the enemy
                auto enemyAmmo = new Ammo;
                (enemies[x]).checkBehaviour(&player);
                if (enemies[x].getBehaviour()->getName() == "Attack") {
                    if (enemyShootClock[x].getElapsedTime().asSeconds() > enemies[x].getWeapon()->getCoolDown() * 3) {
                        enemyAmmo->setPosition(enemies[x].getWeapon()->getPosition());
                        Bulletz[x].push_back(*enemyAmmo);
                        enemyShootClock[x].restart();
                    }
                }
                enemies[x].Action(&player, &enemies[x], *enemyAmmo);
            }

            if (animationClock.getElapsedTime().asSeconds() > 0.15f) { //animation for player
                if (!player.isJumping())
                    countTexture++;

                if (countTexture == 8)
                    countTexture = 0;
                if (dKeyPressed) {
                    if (!player.isCollisionRight())
                        playerAnimation.getTexture(player, countTexture, xMouse, "right");

                } else if (aKeyPressed) {
                    if (!player.isCollisionLeft())
                        playerAnimation.getTexture(player, countTexture, xMouse, "left");

                }

                if (player.getWeapon()->isShoot()) {
                    player.getWeapon()->setShoot(false);
                }

                player.setOrigin(player.getLocalBounds().width / 2, 0);
                animationClock.restart();
            }


            if (weaponClock.getElapsedTime().asSeconds() >
                player.getWeapon()->getCoolDown()) {//adding couldown for weapon
                canShoot = true;
                weaponClock.restart();
            }

            //Adding gravity to the player
            player.setCollisionDown(false);
            player.setCollisionUp(false);
            player.setCollisionRight(false);
            player.setCollisionLeft(false);
            for (int j = 0; j <
                            enemies.size(); j++) {                               //initializing enemies collision with the terrain
                enemies[j].setCollisionDown(false);
                enemies[j].setCollisionUp(false);
                enemies[j].setCollisionRight(false);
                enemies[j].setCollisionLeft(false);
            }
            for (int i = 0; i < enemies.size(); i++) {  //delete enemies when they are dead
                Inventory<Weapon> w;
                Inventory<Usable *> u;
                Weapon a;
                if (enemies[i].getHp() == 0) {

                    enemies[i].releaseInventory(w, u);
                    w.removeElement(enemies[i].getSelectedWeapon(), a);
                    a.realoadTexture();
                    a.setTextureRect(sf::IntRect(0, 0, a.getTexture()->getSize().x / 2 - 1,
                                                 a.getTexture()->getSize().y / 2 - 1));
                    globalWeapon.push_back(a);
                    enemies.erase(enemies.begin() + i);

                }
            }

            for (int j = 0; j < enemies.size(); j++) { //Enemy Weapon position update
                enemies[j].getWeapon()->setTextures(player.getPosition().x, enemies[j].getPosition().x);
                enemies[j].getWeapon()->setPosition(enemies[j].getWeapon()->getPosition().x,
                                                    enemies[j].getPosition().y + enemies[j].getLocalBounds().width / 2 +
                                                    7);
            }

/*checking the player collision with Terrain blocks
*/
            for (auto sprite : blocks) {
                sprite.checkCollision(player);
                for (int y = 0; y < enemyVectorSize; y++)
                    sprite.checkCollision(enemies[y]);
            }
/*
 * Checking the bullet collision,if detected eliminates the bullet from the vecor and shifts the vector's elements.
 * Also,eliinate and shifts the aim's vector elements too.
 */
            for (int z = 0; z < bullets.size(); z++) {
                if (bullets[z].isIsShot()) {
                    bullets[z].shoot(aimI[z], aimF[z]);
                    bullets[z].checkCollision(enemies, blocks);
                    if ((abs(bullets[z].getPosition().x - player.getWeapon()->getPosition().x) >
                         (player.getWeapon()->getRange() * 50)) ||
                        (bullets[z].isGamecharacterCollision() || bullets[z].getTerrainCollision())) {
                        bullets.erase(bullets.begin() + z);
                        aimI.erase(aimI.begin() + z);
                        aimF.erase(aimF.begin() + z);
                    }
                }
            }

            for (int g = 0; g < Bulletz.size(); g++) {
                for (int q = 0; q < Bulletz[g].size(); q++) {
                    Bulletz[g][q].setIsShot(true);
                    if (Bulletz[g][q].isIsShot()) {
                        EaimI.push_back(enemies[g].getPosition());
                        EaimF.push_back(player.getPosition());
                        Bulletz[g][q].shoot(EaimI[g], EaimF[g]);
                        /* if ((abs(Bulletz[g][q].getPosition().x - enemies[g].getWeapon()->getPosition().x) >
                            (enemies[g].getWeapon()->getRange() * 50)) ||
                           (Bulletz[g][q].isGamecharacterCollision() ||Bulletz[g][q].getTerrainCollision())) {
                           Bulletz[g][q].erase(Bulletz.begin() + g);
                           aimI.erase(aimI.begin() + g);
                           aimF.erase(aimF.begin() + g);
                       }*/
                    }
                }
            }

            if (!player.isJumping())                                   //Adding the player gravity map effect
                map.gravityApply(player);

            for (int y = 0; y < enemyVectorSize; y++)               //adding gravity for all the enemies
                map.gravityApply(enemies[y]);

            playerView.setCenter(player.getPosition());         //update view Position

            player.getWeapon()->setTextures(xMouse, player.getPosition().x);// update weapon texture and position
            player.getWeapon()->setPosition(player.getWeapon()->getPosition().x,
                                            player.getPosition().y + player.getLocalBounds().width / 2 + 7);

            playerHud.update(player, playerView); //HUD updating

            renderWin->setView(playerView); // update the vuew

            //RENDER
            renderWin->clear();
            renderMap();
            renderWin->draw(player);
            renderWin->draw(*player.getWeapon());
            for (auto &projectile : bullets) {
                renderWin->draw(projectile);
            }

            for (auto &w : globalWeapon) {
                renderWin->draw(w);
            }

            for (int t = 0; t < Bulletz.size(); t++) {
                for (int k = 0; k < Bulletz[t].size(); k++) {
                    renderWin->draw(Bulletz[t][k]);
                }
            }
            playerHud.render();
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
                        enemies.clear();
                        globalWeapon.clear();
                        for (int i = 0; i < player.getDimWeapon(); i++) {
                            player.removeWeapon(i);
                        }
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
 * function that render the map of the game and enemies
 */
void Game::renderMap() {
    //backGround.setPosition(playerView.getCenter());
    renderWin->draw(backGround);
    for (auto &sprite : blocks) {
        renderWin->draw(sprite);
    }
    for (auto &enemy : enemies) {                               //managing the gravity upon the enemy

        renderWin->draw(enemy);
        renderWin->draw(*enemy.getWeapon());
    }

}
