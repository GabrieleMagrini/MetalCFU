//
// Created by emanuele on 11/09/19.
//

#ifndef METALCFU_ACHIEVEMENT_H
#define METALCFU_ACHIEVEMENT_H

#include <memory>
#include "SFML/Graphics.hpp"

class Achievement : public sf::Sprite {
public:
    explicit Achievement(const std::string &text, const std::string &fontname = "Sources/Raleway-Medium.ttf",
                         const std::string &filename = "Sources/Pngs/trophy.png");

    ~Achievement() override = default;

    void render(sf::RenderWindow &rw);

    std::string getText() const;


private:
    sf::RectangleShape rectangleShape;
    std::shared_ptr<sf::Texture> texture;
    sf::Text text;
    sf::Clock timer;
    std::shared_ptr<sf::Font> font;

};


#endif //METALCFU_ACHIEVEMENT_H
