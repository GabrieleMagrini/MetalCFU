//
// Created by emanuele on 25/07/19.
//

#ifndef METALCFU_BUTTON_H
#define METALCFU_BUTTON_H

#include <iostream>
#include <sstream>

#include "SFML/System.hpp"
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

enum ButtonState {
    IDLE = 0, HOVER, PRESSED
};

class Button {
public:
    Button(float x, float y, float width, float height, sf::Font &font, const std::string &text,
           const std::string &textIdle,
           const std::string &textHover, const std::string &textPressed);

    ~Button() = default;

    void render(sf::RenderTarget &target);

    void update(const sf::Vector2f &mousePos);

    const bool isPressed() const;

    const sf::RectangleShape &getShape() const;

private:
    sf::RectangleShape shape;
    std::unique_ptr<sf::Font> font;
    sf::Text text;

    sf::Texture idleTexture;
    sf::Texture hoverTexture;
    sf::Texture pressedTexture;

    short unsigned buttonState;

};


#endif //METALCFU_BUTTON_H
