//
// Created by emanuele on 11/09/19.
//

#ifndef METALCFU_ACHIEVEMENT_H
#define METALCFU_ACHIEVEMENT_H

#include "SFML/Graphics.hpp"

#include "../Player.h"

class Achievement : public sf::Sprite {
public:
    Achievement(const std::string &text, const sf::Font &f,
                const std::string &filename = "Sources/Pngs/trophy.png");

    ~Achievement() override = default;

    void render(sf::RenderWindow *rw);


private:
    static bool isRendering;
    std::shared_ptr<Player> subject;
    std::shared_ptr<sf::Texture> texture;
    sf::Text text;
    sf::Clock timer;


};


#endif //METALCFU_ACHIEVEMENT_H
