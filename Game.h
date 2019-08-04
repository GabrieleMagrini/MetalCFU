//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAME_H
#define METALCFU_GAME_H

#include <memory>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"
#include "SFML/Audio.hpp"

#include "GameState/GameState.h"
#include "Map.h"
#include "GUI/MainMenu.h"
#include "GUI/OptionMenu.h"
#include "GUI/PauseMenu.h"
#include "Player.h"

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

    void render();

    void update();


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

    //TODO
};


#endif //METALCFU_GAME_H