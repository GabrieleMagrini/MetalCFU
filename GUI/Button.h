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
    Button(float x, float y, float width, float height, const sf::Font &font, const std::string &text,
           const std::string &textIdle,
           const std::string &textHover, const std::string &textPressed);

    Button(float x, float y, float width, float height, const sf::Font &font, const std::string &text,
           const sf::Texture &idleText,
           const sf::Texture &hoverText, const sf::Texture &pressedText);

    Button(Button &b);
    ~Button() = default;

    void render(sf::RenderTarget &target);

    void update(const sf::Vector2f &mousePos);

    const bool isPressed() const;

    const sf::RectangleShape &getShape() const;

    Button &operator=(const Button &b);

    void setCharacterSize(unsigned int size);

    void setButtonTexture(const sf::Texture &idleTexture, const sf::Texture &hoverTexture,
                          const sf::Texture &pressedTexture);

    void setString(const std::string &string);

    std::string getString() const;

private:

    void inizialization(float x, float y, float width, float height, const std::string &text);

    void copy(const Button &b);

    sf::RectangleShape shape;
    std::unique_ptr<sf::Font> font;
    sf::Text text;

    sf::Texture idleTexture;
    sf::Texture hoverTexture;
    sf::Texture pressedTexture;

    short unsigned buttonState;

};


#endif //METALCFU_BUTTON_H
