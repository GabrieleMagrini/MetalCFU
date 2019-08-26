//
// Created by emanuele on 26/08/19.
//

#ifndef METALCFU_GAMEOVERMENU_H
#define METALCFU_GAMEOVERMENU_H

#include <memory>

#include "Button.h"

class GameOverMenu {
public:
    GameOverMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &filename, const sf::Font &font);

    ~GameOverMenu() = default;

    const sf::Texture &getBgTexure() const;

    void setBgTexure(const sf::Texture &bgTexure);

    const sf::Text &getText() const;

    void setText(const sf::Text &text);

    bool isWin() const;

    void setWin(bool win);

    void update();

private:
    std::shared_ptr<sf::RenderWindow> renderWin;
    sf::Sprite backGround;
    sf::Texture bgTexure;
    sf::Text text;
    Button mainMenu;
    Button exitGame;

    bool win;
};


#endif //METALCFU_GAMEOVERMENU_H
