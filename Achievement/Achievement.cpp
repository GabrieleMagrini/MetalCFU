//
// Created by emanuele on 11/09/19.
//

#include "Achievement.h"

Achievement::Achievement(const std::string &text, const sf::Font &f, const string &filename) :
        texture(make_shared<sf::Texture>(sf::Texture{})), text(text, f, 40) {

    texture->loadFromFile(filename);
    this->text.setFillColor(sf::Color(205, 164, 52));
}

void Achievement::render(sf::RenderWindow *rw) {
    if (!isRendering) {
        this->text.setPosition(subject->getPosition());
        setPosition(this->text.getPosition().x - 10, this->text.getPosition().y);
        rw->draw(*this);
        rw->draw(text);
    }
}


