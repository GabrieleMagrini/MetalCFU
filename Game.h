//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAME_H
#define METALCFU_GAME_H

#include <memory>
#include <cmath>
#include <unistd.h>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include "GameState/GameState.h"
#include "GameState/MainMenuState.h"
#include "GameState/GameOverState.h"
#include "GameState/OptionMenuState.h"
#include "GameState/StartGameState.h"
#include "GameState/PauseGameState.h"
#include "GameState/ExitGameState.h"
#include "Map.h"
#include "GUI/MainMenu.h"
#include "GUI/OptionMenu.h"
#include "GUI/PauseMenu.h"
#include "Player.h"
#include "Factory/WeaponFactory.h"
#include "Factory/EnemyFactory.h"
#include "HUD/Hud.h"
#include "Usable.h"
#include "Behaviour/Behaviour.h"
#include "GUI/GameOverMenu.h"
#include "Trampoline.h"
#include "Box.h"
#include "Granade.h"
#include "Barrier.h"
#include "MedKit.h"
#include "Attachment/Attachment.h"
#include "Attachment/ExtendedMagazine.h"
#include "Attachment/LaserScope.h"
#include "Attachment/LongBarrel.h"
#include "Attachment/PowerBarrel.h"
#include "Achievement/DistanceObserver.h"
#include "Achievement/KillObserver.h"
#include "Achievement/BoomObserver.h"

enum class GState {
    GameOver, ExitGame, MainMenu, OptionMenu, StartGame, PauseGame
};

class Game {
public:
    explicit Game(const shared_ptr<sf::RenderWindow> &rw, const sf::Font &font);

    virtual ~Game() = default;

    void gameOverState();

    void exitGameState();

    void mainMenuState();

    void optionMenuState();

    void startGameState();

    void pauseGameState();

    void setState(GState state);

    void loop();


private:

    void renderMap();

    void clear();

    Player player;
    std::unique_ptr<GameState> gameState;
    OptionMenu opMenu;
    MainMenu mainMenu;
    PauseMenu pauseMenu;
    GameOverMenu gameOver;
    std::shared_ptr<sf::RenderWindow> renderWin;
    const std::string wallpaper1 = "Sources/Pngs/wallpaper_1.jpeg";
    sf::Texture textBackGround;
    sf::Sprite backGround;
    sf::Font font;

    Map map;
    std::vector<Terrain> blocks;
    std::vector<Enemy> enemies;
    std::vector<Weapon> globalWeapon;
    std::vector<MedKit> globalUsable;
    std::vector<Interactable *> globalInteractable;
    std::vector<Attachment *> globalAttachments;

    sf::View playerView;
    WeaponFactory weaponFactory;
    EnemyFactory enemyFactory;

    Hud playerHud;

    sf::Event event;

};


#endif //METALCFU_GAME_H