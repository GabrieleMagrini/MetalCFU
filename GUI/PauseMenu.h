//
// Created by emanuele on 31/07/19.
//

#ifndef METALCFU_PAUSEMENU_H
#define METALCFU_PAUSEMENU_H

#include <memory>

#include "Button.h"

class PauseMenu {

    PauseMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &imageFileName, const sf::Font &font);

    ~PauseMenu() = default;

    void update();

    void render();

    bool isBackGameButtonPressed();

    bool isMainMenuButtonPressed();

    void setTextureBackGround(const sf::Texture &texture);
private:

    std::shared_ptr<sf::RenderWindow> renderWin;

    sf::Texture textBackGround;
    sf::Sprite backGround;

    Button backGameButton;
    Button mainMenuButton;
};


#endif //METALCFU_PAUSEMENU_H
