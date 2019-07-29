//
// Created by emanuele on 26/07/19.
//

#ifndef METALCFU_OPTIONMENU_H
#define METALCFU_OPTIONMENU_H

#include <memory>
#include "SFML/Graphics.hpp"
#include "SFML/System.hpp"

#include "Button.h"


class OptionMenu {
public:
    OptionMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &filename, const sf::Font &font);

    void render();

    void update();

    bool isVolumeButtonPressed();

    bool isResButtonPressed();

    bool isCancelButtonPressed();

    bool isSaveButtonPressed();
private:

    sf::Texture backGrTexture;
    sf::Sprite backGround;

    std::shared_ptr<sf::RenderWindow> renderWin;

    sf::Texture onTextureIdle;
    sf::Texture onTextureHover;
    sf::Texture onTexturePressed;

    sf::Texture offTextureIdle;
    sf::Texture offTextureHover;
    sf::Texture offTexturePressed;

    sf::Text volumeTxt;
    sf::Text resTxt;

    Button volButton;
    Button resButton;
    Button saveButton;
    Button cancelButton;
};


#endif //METALCFU_OPTIONMENU_H
