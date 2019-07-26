//
// Created by emanuele on 25/07/19.
//

#include "Button.h"

/***
 *
 * @param x position x of the button
 * @param y position y of the button
 * @param width of the button
 * @param height of the button
 * @param font of the button
 * @param text of the button
 * @param textIdle file name of texture for button when mouse idle
 * @param textHover file name of texture for button when mouse hover
 * @param textPressed file name of texture for button when mouse press it
 */
Button::Button(float x, float y, float width, float height, sf::Font font, const std::string text,
               const std::string textIdle,
               const std::string textHover, const std::string textPressed) :
        font(std::unique_ptr<sf::Font>(new sf::Font(font))), text(), buttonState(ButtonState::IDLE) {


    if (!idleTexture.loadFromFile(textIdle)) {
        std::cerr << "can't access to file" << std::endl;
    }
    if (!hoverTexture.loadFromFile(textHover)) {
        std::cerr << "can't access to file" << std::endl;
    }
    if (!pressedTexture.loadFromFile(textPressed)) {
        std::cerr << "can't access to file" << std::endl;
    }

    inizialization(x, y, width, height, text);
}

/***
 *
 * @param x position x of the button
 * @param y position y of the button
 * @param width of the button
 * @param height of the button
 * @param font of the button
 * @param text of the button
 * @param idleText texture for button when mouse idle
 * @param hoverText texture for button when mouse hover
 * @param pressedText texture for button when mouse press it
 */
Button::Button(float x, float y, float width, float height, sf::Font font, std::string text, sf::Texture idleText,
               sf::Texture hoverText, sf::Texture pressedText) : font(std::unique_ptr<sf::Font>(new sf::Font(font))),
                                                                 text(), buttonState(ButtonState::IDLE),
                                                                 idleTexture(idleText), hoverTexture(hoverText),
                                                                 pressedTexture(pressedText) {
    inizialization(x, y, width, height, std::move(text));
}


/**
 * rendering the shape
 * @param target the renderTarget
 */
void Button::render(sf::RenderTarget &target) {
    target.draw(shape);
    target.draw(text);

}

/**
 * update boolean for hover and pressed
 * @param mousePos
 */
void Button::update(const sf::Vector2f &mousePos) {
    buttonState = IDLE;

    if (shape.getGlobalBounds().contains(mousePos)) {
        buttonState = HOVER;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            this->buttonState = PRESSED;
        }
    }

    switch (buttonState) {
        case IDLE:

            shape.setTexture(&idleTexture);
            break;

        case HOVER:
            shape.setTexture(&hoverTexture);
            break;

        case PRESSED:
            shape.setTexture(&pressedTexture);
            break;
        default:
            shape.setFillColor(sf::Color::Red);
            break;
    }

}

/***
 * copy constructor
 * @param b
 */
Button::Button(Button &b) {
    copy(b);
}

/***
 * function that check if the button is pressed
 * @return
 */
const bool Button::isPressed() const {
    bool b = false;

    if (buttonState == PRESSED)
        b = true;
    return b;
}

const sf::RectangleShape &Button::getShape() const {
    return shape;
}

void Button::inizialization(float x, float y, float width, float height, std::string text) {
    shape.setSize(sf::Vector2f(width, height));
    shape.setPosition(x, y);

    shape.setTexture(&idleTexture);

    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::White);
    this->text.setCharacterSize(24);

    //center text in the rectangle shape
    this->text.setOrigin(shape.getLocalBounds().left + shape.getLocalBounds().width / 2.0f,
                         shape.getLocalBounds().top + shape.getLocalBounds().height / 2.0f);

    this->text.setPosition(sf::Vector2f(
            shape.getPosition().x + shape.getGlobalBounds().width - this->text.getLocalBounds().width / 2.0f,
            shape.getPosition().y + shape.getGlobalBounds().height -
            this->text.getLocalBounds().height));
}

Button &Button::operator=(const Button &b) {
    copy(b);
    return *this;
}

void Button::copy(const Button &b) {
    this->shape = b.shape;
    this->text = b.text;
    this->font = std::unique_ptr<sf::Font>(new sf::Font(*b.font));
    this->idleTexture = b.idleTexture;
    this->hoverTexture = b.hoverTexture;
    this->pressedTexture = b.pressedTexture;

    this->buttonState = b.buttonState;
}
