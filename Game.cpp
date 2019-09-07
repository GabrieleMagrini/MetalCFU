//
// Created by emanuele on 24/07/19.
//

#include "Game.h"


Game::Game(const shared_ptr<sf::RenderWindow> &rw, const sf::Font &font)
        : gameState(new MainMenuState{}), renderWin(rw), font(font),
          mainMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          opMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          pauseMenu(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          gameOver(rw, "Sources/Pngs/wallpaper_1.jpeg", font),
          player(3, weaponFactory.createWeapon(WeaponType::pistol).get(), new Granade{30, 5}, 100, 20),
          playerView(sf::FloatRect(renderWin->getPosition().x, renderWin->getPosition().y, renderWin->getSize().x,
                                   renderWin->getSize().y)), playerHud(rw, font), event() {
    renderWin->setFramerateLimit(30);
    renderWin->setKeyRepeatEnabled(false);
    textBackGround.loadFromFile("Sources/Pngs/wallpaper_1.jpeg");
    backGround.setTexture(textBackGround);
    backGround.setPosition(0, 0);
    float scaleX = static_cast<float>((renderWin->getSize().x) / static_cast<float>(textBackGround.getSize().x));
    float scaleY = static_cast<float>((renderWin->getSize().y) / static_cast<float>(textBackGround.getSize().y));
    backGround.setScale(scaleX, scaleY);
    player.setOrigin(player.getLocalBounds().width / 2, 0);
    player.setTextures(0, 0, "right");
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
            gameState = std::unique_ptr<GameState>(new GameOverState{});
            break;

        case GState::MainMenu:
            gameState = std::unique_ptr<GameState>(new MainMenuState{});
            break;

        case GState::OptionMenu:
            gameState = std::unique_ptr<GameState>(new OptionMenuState{});
            break;

        case GState::StartGame:
            gameState = std::unique_ptr<GameState>(new StartGameState{});
            break;

        case GState::PauseGame:
            gameState = std::unique_ptr<GameState>(new PauseGameState{});
            break;


        case GState::ExitGame:
            gameState = std::unique_ptr<GameState>(new ExitGameState{});
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

    int mapCount = 0;
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

    sf::SoundBuffer playerShoot;
    playerShoot.loadFromFile("Sources/Sounds/shot.wav");
    sf::Sound shotSound;
    shotSound.setBuffer(playerShoot);

    sf::SoundBuffer enemyShoot;
    enemyShoot.loadFromFile("Sources/Sounds/enemyShoot.wav");
    sf::Sound enemyShotSound;
    enemyShotSound.setBuffer(enemyShoot);

    Granade *tempGranade = nullptr;
    MedKit *tempMedKit = nullptr;


    sf::Texture screenShoot;

    while (renderWin->isOpen()) {
        if (gameState->getStateName() == "MainMenu") {    //MainMenu loop
            while (renderWin->pollEvent(event)) {

                if (event.type == sf::Event::Closed)
                    exitGameState();

                if (event.type == sf::Event::MouseButtonReleased || mainMenu.isNextLevel()) {
                }
                if (mainMenu.isStartButtonPressed() || mainMenu.isNextLevel()) {
                    mainMenu.setNextLevel(false);
                    std::stringstream stream;
                    String s;
                    stream << "Sources/Maps/mappa" << mapCount + 1 << ".txt";
                    s = stream.str();
                    blocks = map.createMap(std::ifstream(s));
                    enemies = std::vector<Enemy>(enemyVectorSize, *enemyFactory.createEnemy(EnemyType::Soldier));
                    for (int j = 0; j <
                                    enemies.size(); j++) {
                        enemies[j] = *enemyFactory.createEnemy(
                                EnemyType::Soldier);   //Placing the enemies in the map
                        enemies[j].setPosition(blocks[15 + j].getPosition().x + 500 * j, 250);


                    }
                    globalInteractable.push_back(new Trampoline{});
                    globalInteractable.push_back(new Box<Weapon>{*weaponFactory.createWeapon(WeaponType::M4)});
                    globalInteractable.push_back(new Barrier{});
                    globalInteractable.push_back(new Box<MedKit>{*new MedKit});
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

                    player = Player{3, weaponFactory.createWeapon(WeaponType::pistol).get(), new MedKit,
                                    100, 20, 100, 300};
                    for (auto &block : blocks) {
                        if (block.isSpawnPoint()) {
                            player.setPosition(block.getPosition().x + 30, block.getPosition().y - 100);
                            break;
                        }
                    }

                    player.setUsable(new Granade{30, 3});
                    enemyShootClock = vector<sf::Clock>(enemyVectorSize);

                    animationClock.restart();
                    weaponClock.restart();
                    granadeClock.restart();
                    countTextureGranade = 0;
                    for (auto a  : enemyShootClock) {
                        a.restart();
                    }
                    startGameState();
                } else if (mainMenu.isOptionButtonPressed()) {
                    optionMenuState();

                } else if (mainMenu.isExitButtonPressed()) {
                    exitGameState();
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
                                    shotSound.play();
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
                            for (int u = 0; u < globalUsable.size(); u++) {
                                if (globalUsable[u].getGlobalBounds().intersects(player.getGlobalBounds())) {

                                    if (dynamic_cast<MedKit *>(&globalUsable[u]) != nullptr) {
                                        auto us = new MedKit;
                                        player.setUsable(us);
                                        globalUsable.erase(globalUsable.begin() + u);
                                    } else if (dynamic_cast<Granade *>(&globalUsable[u]) != nullptr) {
                                        auto us = new Granade(*dynamic_cast<Granade *>(&globalUsable[u]));
                                        player.setUsable(us);
                                        globalUsable.erase(globalUsable.begin() + u);
                                    }

                                }
                            }
                            break;
                        }


                        case sf::Keyboard::Num1:
                            numKey = player.getSelectedWeapon();
                            player.setSelectedWeapon(0);
                            if (player.getWeapon() == nullptr)
                                player.setSelectedWeapon(numKey);
                            break;
                        case sf::Keyboard::Num2:
                            numKey = player.getSelectedWeapon();
                            player.setSelectedWeapon(1);
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
                            if (tempGranade == nullptr)
                                for (int i = 0; i < player.getDimUsable(); i++) {

                                    tempGranade = dynamic_cast<Granade *>(player.getUsable(i));
                                    if (tempGranade != nullptr) {
                                        tempGranade = dynamic_cast<Granade *>(player.removeUsable(i));

                                        tempGranade->setDirection((xMouse > player.getPosition().x));
                                        break;
                                    }
                                }

                            if (tempGranade != nullptr && !tempGranade->isTrow()) {
                                tempGranade->setTrow(true);
                                tempGranade->setPosition(player.getPosition());
                            }
                            granadeClock.restart();

                        }
                            break;

                        case sf::Keyboard::M: //Use MedKit
                        {
                            if (tempMedKit == nullptr && player.getHp() < 100) {
                                for (int i = 0; i < player.getDimUsable(); i++) {
                                    tempMedKit = dynamic_cast<MedKit *>(player.getUsable(i));
                                    if (tempMedKit != nullptr) {
                                        tempMedKit->use(player);
                                        tempMedKit = nullptr;
                                        player.removeUsable(i);
                                    }
                                    break;
                                }
                            }
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
                player.setTextures(0, xMouse, "right");
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
                        player.setTextures(countTexture, xMouse, "right");

                } else if (aKeyPressed) {
                    if (!player.isCollisionLeft())
                        player.setTextures(countTexture, xMouse, "left");

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
                player.setPosition(100, 300);
                for (auto &block : blocks) {
                    if (block.isSpawnPoint()) {
                        player.setPosition(block.getPosition().x, block.getPosition().y - 100);
                        break;
                    }
                }
            }

            if (player.getLives() == 0) {
                gameOver.setWin(false);
                gameOverState();

            } else if (enemies.empty()) {
                gameOver.setWin(true);
                gameOverState();
            }

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
                        auto sound = new sf::Sound;
                        sound->setBuffer(enemyShoot);
                        sound->play();
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

            for (auto &enemy : enemies) { //Enemy Weapon position update
                enemy.getWeapon()->setTextures(player.getPosition().x, enemy.getPosition().x);
                enemy.getWeapon()->setPosition(enemy.getWeapon()->getPosition().x,
                                               enemy.getPosition().y + enemy.getLocalBounds().width / 2 +
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

            for (auto &enemy : enemies) {                               //initializing enemies collision with the terrain
                enemy.setCollisionDown(false);
                enemy.setCollisionUp(false);
                enemy.setCollisionRight(false);
                enemy.setCollisionLeft(false);
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
                        W.realoadTexture();
                        W.setTextureRect(
                                sf::IntRect(0, 0, W.getTexture()->getSize().x / 2,
                                            W.getTexture()->getSize().y / 2));
                        globalWeapon.push_back(W);
                        globalInteractable.erase(globalInteractable.begin() + Z);
                    } else if (dynamic_cast<Barrier *>(globalInteractable[Z]) != nullptr) {
                        globalInteractable.erase(globalInteractable.begin() + Z);
                    } else if (dynamic_cast<Box<MedKit> *>(globalInteractable[Z]) != nullptr) {
                        MedKit M;
                        M = dynamic_cast<Box<MedKit> *>(globalInteractable[Z])->dropGift();
                        M.setPosition(globalInteractable[Z]->getPosition());
                        M.setTextureRect(
                                sf::IntRect(0, 0, M.getTexture()->getSize().x,
                                            M.getTexture()->getSize().y));
                        globalUsable.push_back(M);
                        globalInteractable.erase(globalInteractable.begin() + Z);
                    }
                }
            }



            //Add a fake gravity to the interactable objects,now easier to put in the map

            for (auto &inter : globalInteractable) {
                inter->setPosition(inter->getPosition().x,
                                   inter->getPosition().y + 20);
                for (auto &sprite :blocks) {
                    if (inter->getGlobalBounds().intersects(sprite.getGlobalBounds()))
                        inter->setPosition(inter->getPosition().x,
                                           inter->getPosition().y - 20);
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

            if (tempGranade != nullptr) {
                if (tempGranade->isTrow()) {
                    tempGranade->setCollision(false);
                    for (auto &t: blocks) {
                        if (tempGranade->getGlobalBounds().intersects(t.getGlobalBounds()))
                            tempGranade->setCollision(true);
                    }

                    tempGranade->use(player);
                    if (tempGranade->getExplosionTime() > 0 && !tempGranade->isCollision()) {
                        tempGranade->move(0, map.getGravity() / 1.5f);
                    }
                    if (granadeClock.getElapsedTime().asSeconds() > tempGranade->getExplosionTime() &&
                        tempGranade->getExplosionTime() > 0) {
                        tempGranade->setExplosionTime(0);
                        granadeClock.restart();
                    }
                    if (tempGranade->getExplosionTime() == 0) { //granade explosion
                        tempGranade->checkHit(enemies);

                        if (granadeClock.getElapsedTime().asSeconds() > 0.06f) {
                            tempGranade->setTextureExpl(countTextureGranade);
                            countTextureGranade++;
                            if (countTextureGranade > 8) {
                                tempGranade = nullptr;
                            }
                            granadeClock.restart();
                        }
                    }

                } else
                    tempGranade->setPosition(player.getPosX(), player.getPosY());

            }

            //weapon position update, is here for better know the position of the player that can change by interactable
            player.getWeapon()->setPosition(player.getWeapon()->getPosition().x,
                                            player.getPosition().y + player.getLocalBounds().width / 2 + 7);


            playerHud.update(player, playerView); //HUD updating

            renderWin->setView(playerView); // update the view

            for (auto &w : globalWeapon) {
                w.realoadTexture();
            }

            //RENDER
            renderWin->clear();

            renderMap();

            renderWin->draw(player);
            renderWin->draw(*player.getWeapon());
            if (tempGranade != nullptr && tempGranade->isTrow())
                renderWin->draw(*tempGranade);

            for (auto &projectile : bullets) {
                renderWin->draw(projectile);
            }

            for (auto &inter : globalInteractable) {
                renderWin->draw(*inter);
            }
            for (auto &usable : globalUsable) {
                renderWin->draw(usable);
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
                        mapCount = 0;
                        mainMenu.setNextLevel(false);
                        enemies.clear();
                        globalWeapon.clear();
                        globalInteractable.clear();
                        globalUsable.clear();
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
                        bullets.clear();
                        Bulletz.clear();
                        enemyBullets.clear();
                        mapCount = 0;
                        globalWeapon.clear();
                        blocks.clear();
                        globalInteractable.clear();
                        globalUsable.clear();
                        for (int i = 0; i < player.getDimWeapon(); i++) {
                            player.removeWeapon(i);
                        }

                        mainMenuState();
                    } else if (gameOver.isNextLevelPressed()) {
                        mapCount += 1;
                        enemies.clear();
                        bullets.clear();
                        Bulletz.clear();
                        enemyBullets.clear();
                        globalWeapon.clear();
                        blocks.clear();
                        globalInteractable.clear();
                        globalUsable.clear();
                        mainMenu.setNextLevel(true);
                        enemyVectorSize = enemyVectorSize + mapCount;
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
