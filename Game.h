//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAME_H
#define METALCFU_GAME_H

#include <memory>
#include <cmath>
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
#include "utility/CharacterAnimation.h"
#include "Factory/WeaponFactory.h"
#include "Factory/EnemyFactory.h"

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

    Player player;
    std::unique_ptr<GameState> gameState;
    OptionMenu opMenu;
    MainMenu mainMenu;
    PauseMenu pauseMenu;
    std::shared_ptr<sf::RenderWindow> renderWin;
    const std::string wallpaper1 = "Sources/Pngs/wallpaper_1.jpeg";
    sf::Texture textBackGround;
    sf::Sprite backGround;
    sf::Font font;

    Map map;
    std::vector<Terrain> blocks;

    sf::View playerView;
    CharacterAnimation playerAnimation;
    WeaponFactory weaponFactory;
    EnemyFactory enemyFactory;
    //TODO
};


#endif //METALCFU_GAME_H