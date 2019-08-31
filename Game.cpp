//
// Created by emanuele on 24/07/19.
//

#include "Game.h"


Game::Game(const shared_ptr<sf::RenderWindow> &rw, const sf::Font &font)
        : gameState(new MainMenuState()), renderWin(rw), font(font),
          mainMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          opMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          pauseMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          gameOver(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          player(3, weaponFactory.createWeapon(WeaponType::pistol).get(), new Granade(30, 5), 100, 20),
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
    sf::Clock granadeClock;
    std::vector<sf::Clock> enemyShootClock;
    int countTexture = 0;
    int countTextureGranade = 0;
    int enemyVectorSize = 5;

    float xStart = 0;
    float yStart = 0;
    float xPressed = 0;
    float yPressed = 0;
    vector<Ammo> bullets;
    vector<Ammo> enemyBullets;
    vector<vector<Ammo>> Bulletz;
    //A trampoline and a box to showcase the Interactable objects and their effects
    Trampoline t;
    Weapon x = *(weaponFactory.createWeapon(WeaponType::AK_47));
    Box<Weapon> b(x);
    Barrier B;
    globalInteractable.push_back(&t);
    globalInteractable.push_back(&b);
    globalInteractable.push_back(&B);
    Granade *granade1 = nullptr;

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
                            enemies[j].setPosition(blocks[15 + j].getPosition().x + 500 * j, 250);


                        }
                        globalInteractable[0]->setScale(2, 2);
                        globalInteractable[1]->setScale(1.5, 1.5);
                        globalInteractable[2]->setScale(1, 1.5);
                        for (int j = 0; j <
                                        globalInteractable.size(); j++) {
                            globalInteractable[j]->setPosition(blocks[15 + j].getPosition().x + 300 * (j + 1), 250);
                        }
                        Bulletz = vector<vector<Ammo>>(enemies.size());
                        float scaleX = static_cast<float>(blocks.back().getPosition().x) /
                                       static_cast<float>(textBackGround.getSize().x);
                        float scaleY = static_cast<float>(blocks.back().getPosition().y) /
                                       static_cast<float>(textBackGround.getSize().y);
                        backGround.setPosition(-500, -100);
                        backGround.setScale(scaleX + 1, scaleY + 1);

                        player = Player(3, weaponFactory.createWeapon(WeaponType::pistol).get(), new Granade(30, 5),
                                        100, 20,
                                        static_cast<int>(blocks[1].getPosition().x) + 100, 400);
                        enemyShootClock = vector<sf::Clock>(enemyVectorSize);

                        animationClock.restart();
                        weaponClock.restart();
                        granadeClock.restart();
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
                                player.getAimInitial().push_back(Start);
                                Vector2f Fin(xPressed, yPressed);
                                player.getAimFinal().push_back(Fin);

                                if (!player.getWeapon()->getCurrentAmmo().empty() ||
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
                    int numKey = 0;
                    switch (event.key.code) {
                        case sf::Keyboard::Escape:
                            screenShoot.create(static_cast<int>(renderWin->getView().getSize().x),
                                               static_cast<int>(renderWin->getView().getSize().y));
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

                        case sf::Keyboard::F: { //Weapon pickup
                            bool addAmmo = false;
                            for (int i = 0; i < globalWeapon.size(); i++) {
                                if (globalWeapon[i].getGlobalBounds().intersects(player.getGlobalBounds())) {
                                    for (int j = 0; j < player.getDimWeapon(); j++) {

                                        if (player.getWeapon(j) != nullptr)
                                            if ((globalWeapon[i].getName() == player.getWeapon(j)->getName())) {
                                                player.getWeapon(j)->addAmmo(5);
                                                player.getWeapon(j)->addAmmo(globalWeapon[i].getCurrentAmmo().size());
                                                addAmmo = true;
                                            }
                                    }
                                    if (!addAmmo) {
                                        globalWeapon[i].addAmmo(15);
                                        auto w1 = player.setWeapon(&globalWeapon[i]);
                                        if (w1 != nullptr) {

                                            globalWeapon[i] = *w1;
                                        } else {
                                            globalWeapon.erase(globalWeapon.begin() + i);
                                        }

                                    } else {
                                        globalWeapon.erase(globalWeapon.begin() + i);
                                    }

                                }
                            }
                            break;
                        }
                        case sf::Keyboard::Num2:
                            numKey = player.getSelectedWeapon();
                            player.setSelectedWeapon(1);
                            if (player.getWeapon() == nullptr)
                                player.setSelectedWeapon(numKey);

                            break;

                        case sf::Keyboard::Num1:
                            numKey = player.getSelectedWeapon();
                            player.setSelectedWeapon(0);
                            if (player.getWeapon() == nullptr)
                                player.setSelectedWeapon(numKey);
                            break;

                        case sf::Keyboard::Num3:
                            numKey = player.getSelectedWeapon();
                            player.setSelectedWeapon(2);
                            if (player.getWeapon() == nullptr)
                                player.setSelectedWeapon(numKey);
                            break;

                        case sf::Keyboard::Num4:
                            numKey = player.getSelectedWeapon();
                            player.setSelectedWeapon(3);
                            if (player.getWeapon() == nullptr)
                                player.setSelectedWeapon(numKey);
                            break;

                        case sf::Keyboard::T: //launch granade
                        {
                            if (granade1 == nullptr)
                                for (int i = 0; i < player.getDimUsable(); i++) {
                                    granade1 = dynamic_cast<Granade *>(player.getUsable(i));
                                    if (granade1 != nullptr) {
                                        granade1->setDirection((xMouse > player.getPosition().x));
                                        break;
                                    }
                                }

                            if (granade1 != nullptr && !granade1->isTrow()) {
                                granade1->setTrow(true);
                                granade1->setPosition(player.getPosition());
                            }
                            granadeClock.restart();

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

            //PLAYER UPDATE
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

            if (player.getHp() == 0 || player.getPosition().y > blocks[blocks.size() - 1].getPosition().y) {
                player.setLives(player.getLives() - 1);
                player.setHp(100);
                player.setPosition(blocks[1].getPosition().x + 100, 400);
            }

            if (player.getLives() == 0) {
                gameOver.setWin(false);
                gameOverState();

            } /*else if (enemies.empty()) {
                gameOver.setWin(true);
                gameOverState();
            }*/

            if (!player.isJumping())                                   //Adding the player gravity map effect
                map.gravityApply(player);


            //WEAPON PLAYER UPDATE

            for (auto &w: globalWeapon) { //reload texture for weapon
                w.realoadTexture();
            }

            if (weaponClock.getElapsedTime().asSeconds() >
                player.getWeapon()->getCoolDown()) {//adding couldown for weapon
                canShoot = true;
                weaponClock.restart();
            }

            /*
           * Checking the bullet collision,if detected eliminates the bullet from the vecor and shifts the vector's elements.
           * Also,eliinate and shifts the aim's vector elements too.
           */
            for (int z = 0; z < bullets.size(); z++) {
                if (bullets[z].isIsShot()) {
                    bullets[z].shoot(player.getAimInitial()[z], player.getAimFinal()[z]);
                    bullets[z].checkCollision(enemies, blocks, globalInteractable);
                    if ((abs(bullets[z].getPosition().x - player.getWeapon()->getPosition().x) >
                         (player.getWeapon()->getRange() * 50)) ||
                        (bullets[z].isGamecharacterCollision() || bullets[z].getTerrainCollision() ||
                         bullets[z].isInteractableCollision())) {
                        bullets.erase(bullets.begin() + z);
                        player.getAimInitial().erase(player.getAimInitial().begin() + z);
                        player.getAimFinal().erase(player.getAimFinal().begin() + z);
                    }
                }
            }

            player.getWeapon()->setTextures(xMouse, player.getPosition().x);// update weapon texture and position


            //UPDATE ENEMY
            for (int x = 0; x < enemies.size(); x++) {  //adding behaviour to the enemy
                auto enemyAmmo = new Ammo;
                (enemies[x]).checkBehaviour(&player);
                if (enemies[x].getBehaviour()->getName() == "Attack") {
                    if (enemyShootClock[x].getElapsedTime().asSeconds() > enemies[x].getWeapon()->getCoolDown() * 3) {
                        enemyAmmo->setPosition(enemies[x].getWeapon()->getPosition());
                        enemyAmmo->setIsShot(true);
                        enemies[x].Action(&player, &enemies[x], *enemyAmmo);
                        Bulletz[x].push_back(*enemyAmmo);
                        enemyShootClock[x].restart();
                        sf::Vector2f EnI = enemies[x].getPosition();
                        sf::Vector2f EnF = player.getPosition();
                        enemies[x].getAimInitial().push_back(EnI);
                        enemies[x].getAimFinal().push_back(EnF);
                    }
                } else
                    enemies[x].Action(&player, &enemies[x], *enemyAmmo);
            }




            for (int i = 0; i < enemies.size(); i++) {  //delete enemies when they are dead
                Inventory<Weapon> w;
                Inventory<Usable *> u;
                Weapon a;
                if (enemies[i].getHp() == 0 || enemies[i].getPosition().y > blocks[blocks.size() - 1].getPosition().y) {

                    enemies[i].releaseInventory(w, u);
                    w.removeElement(enemies[i].getSelectedWeapon(), a);
                    a.setTextureRect(sf::IntRect(0, 0, a.getTexture()->getSize().x / 2 - 1,
                                                 a.getTexture()->getSize().y / 2 - 1));
                    Bulletz.erase(Bulletz.begin() +
                                  i);                                                 //Erase the bullet shoot from the dead enemy
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


            for (int g = 0; g < enemies.size(); g++) { //check bullets of the enemy collision
                for (int q = 0; q < Bulletz[g].size(); q++) {
                    if (Bulletz[g][q].isIsShot()) {
                        Bulletz[g][q].shoot(enemies[g].getAimInitial()[q], enemies[g].getAimFinal()[q]);
                        Bulletz[g][q].checkPlayerCollision(player, blocks, globalInteractable);
                        if ((abs(Bulletz[g][q].getPosition().x - enemies[g].getWeapon()->getPosition().x) >
                             (enemies[g].getWeapon()->getRange() * 50)) ||
                            (Bulletz[g][q].isGamecharacterCollision() || Bulletz[g][q].getTerrainCollision() ||
                             Bulletz[g][q].isInteractableCollision())) {
                            Bulletz[g].erase(Bulletz[g].begin() + q);
                            if (!enemies[g].getAimInitial().empty())
                                enemies[g].getAimInitial().erase(enemies[g].getAimInitial().begin() + q);
                            if (!enemies[g].getAimFinal().empty())
                                enemies[g].getAimFinal().erase(enemies[g].getAimFinal().begin() + q);
                        }
                    }
                }
            }

            for (int y = 0; y < enemyVectorSize; y++)               //adding gravity for all the enemies
                map.gravityApply(enemies[y]);

            //UPDATE TERRAIN

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
            for (auto sprite : blocks) { //check for player and enemies collision with blocks
                sprite.checkCollision(player);
                for (int y = 0; y < enemyVectorSize; y++)
                    sprite.checkCollision(enemies[y]);
            }


            //UPDATE INTERACTABLE

            for (int Z = 0; Z < globalInteractable.size(); Z++) {
                if (globalInteractable[Z]->getHp() <= 0) {
                    if (dynamic_cast<Box<Weapon> *>(globalInteractable[Z]) != nullptr) {
                        Weapon W;
                        W = dynamic_cast<Box<Weapon> *>(globalInteractable[Z])->dropGift();
                        W.setPosition(globalInteractable[Z]->getPosition());
                        W.setTextureRect(sf::IntRect(0, 0, W.getTexture()->getSize().x / 2 - 1,
                                                     W.getTexture()->getSize().y / 2 - 1));
                        globalWeapon.push_back(W);
                        globalInteractable.erase(globalInteractable.begin() + Z);
                    } else if (dynamic_cast<Barrier *>(globalInteractable[Z]) != nullptr) {
                        globalInteractable.erase(globalInteractable.begin() + Z);
                    }
                }
            }



            //Add a fake gravity to the interactable objects,now easier to put in the map

            for (int Z = 0; Z < globalInteractable.size(); Z++) {
                globalInteractable[Z]->setPosition(globalInteractable[Z]->getPosition().x,
                                                   globalInteractable[Z]->getPosition().y + 20);
                for (auto &sprite :blocks) {
                    if (globalInteractable[Z]->getGlobalBounds().intersects(sprite.getGlobalBounds()))
                        globalInteractable[Z]->setPosition(globalInteractable[Z]->getPosition().x,
                                                           globalInteractable[Z]->getPosition().y - 20);
                }
            }



            //check the Trampoline collision,at the moment just 1 element

            if (player.getGlobalBounds().intersects(globalInteractable[0]->getGlobalBounds())) {
                globalInteractable[0]->setCollision(true);
            }
            if (globalInteractable[0]->getCollision()) {
                dynamic_cast<Trampoline *>(globalInteractable[0])->liftUp(&player);
            }


            playerView.setCenter(player.getPosition());         //update view Position

            //UPDATE GRANADE

            if (granade1 != nullptr) {
                if (granade1->isTrow()) {
                    granade1->setCollision(false);
                    for (auto &t: blocks) {
                        if (granade1->getGlobalBounds().intersects(t.getGlobalBounds()))
                            granade1->setCollision(true);
                    }

                    granade1->use(player);
                    if (granade1->getExplosionTime() > 0 && !granade1->isCollision()) {
                        granade1->move(0, map.getGravity() / 1.5f);
                    }
                    if (granadeClock.getElapsedTime().asSeconds() > granade1->getExplosionTime() &&
                        granade1->getExplosionTime() > 0) {
                        granade1->setExplosionTime(0);
                        granadeClock.restart();
                    }
                    if (granade1->getExplosionTime() == 0) { //granade explosion
                        granade1->checkHit(enemies);

                        if (granadeClock.getElapsedTime().asSeconds() > 0.06f) {
                            granade1->setTextureExpl(countTextureGranade);
                            countTextureGranade++;
                            if (countTextureGranade > 8) {
                                granade1 = nullptr;
                            }
                            granadeClock.restart();
                        }
                    }

                } else
                    granade1->setPosition(player.getPosX(), player.getPosY());

            }

            //weapon position update, is here for better know the position of the player that can change by interactable
            player.getWeapon()->setPosition(player.getWeapon()->getPosition().x,
                                            player.getPosition().y + player.getLocalBounds().width / 2 + 7);


            playerHud.update(player, playerView); //HUD updating

            renderWin->setView(playerView); // update the view

            //RENDER
            renderWin->clear();

            renderMap();

            renderWin->draw(t);

            renderWin->draw(player);
            renderWin->draw(*player.getWeapon());
            if (granade1 != nullptr && granade1->isTrow())
                renderWin->draw(*granade1);

            for (auto &projectile : bullets) {
                renderWin->draw(projectile);
            }

            for (int I = 0; I < globalInteractable.size(); I++) {
                renderWin->draw(*globalInteractable[I]);
            }

            for (auto &w : globalWeapon) {
                renderWin->draw(w);
            }

            for (int idx = 0; idx < Bulletz.size(); idx++) {
                for (int k = 0; k < Bulletz[idx].size(); k++) {
                    renderWin->draw(Bulletz[idx][k]);
                }
            }
            playerHud.render();
            renderWin->display();

        } else if (gameState->getStateName() == "PauseGame") {      //pause menu
            playerView.setCenter(renderWin->getView().getSize().x / 2.0f, renderWin->getView().getSize().y / 2.0f);
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

        } else if (gameState->getStateName() == "GameOver") { //Game over state
            playerView.setCenter(renderWin->getView().getSize().x / 2.0f, renderWin->getView().getSize().y / 2.0f);
            renderWin->setView(playerView);
            while (renderWin->pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    renderWin->close();

                if (event.type == sf::Event::MouseButtonReleased) {
                    if (gameOver.isExitButtonPressed()) {
                        exitGameState();
                    } else if (gameOver.isMainMenuPressed()) {
                        enemies.clear();
                        globalWeapon.clear();
                        for (int i = 0; i < player.getDimWeapon(); i++) {
                            player.removeWeapon(i);
                        }
                        mainMenuState();
                    }
                }

            }
            gameOver.update();
            gameOver.render();
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
    for (auto &enemy : enemies) {                               //rendering Enemy

        renderWin->draw(enemy);
        renderWin->draw(*enemy.getWeapon());
    }

}
