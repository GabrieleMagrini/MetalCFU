//
// Created by emanuele on 26/07/19.
//

#ifndef METALCFU_MAINMENU_H
#define METALCFU_MAINMENU_H

#include <memory>

#include "SFML/Graphics.hpp"
#include "Button.h"

class MainMenu {
public:
    MainMenu(std::unique_ptr<sf::RenderWindow> rw, const std::string &filename, const sf::Font &font);

    void render();

    void update();

    bool exitButtonPressed();

    bool optionButtonPressed();

    bool startButtonPressed();

private:
    sf::Texture backText;
    sf::Sprite backGround;
    std::unique_ptr<sf::RenderWindow> renderWin;
    Button startButton;
    Button optionButton;
    Button exitButton;
};


#endif //METALCFU_MAINMENU_H
