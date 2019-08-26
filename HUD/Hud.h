//
// Created by emanuele on 16/08/19.
//

#ifndef METALCFU_HUD_H
#define METALCFU_HUD_H

#include <memory>
#include <sstream>

#include "../Ammo.h"
#include "../Player.h"

class Hud {
public:
    explicit Hud(std::shared_ptr<sf::RenderWindow> renderWin, const sf::Font &font);

    void render();

    void update(Player &p, sf::View &view);

private:
    std::shared_ptr<sf::RenderWindow> renderWin;
    sf::Text weaponAmmo;
    sf::Text lives;
    sf::RectangleShape life;
    sf::RectangleShape lifeBorder;

    int maxSizeX;
};


#endif //METALCFU_HUD_H
