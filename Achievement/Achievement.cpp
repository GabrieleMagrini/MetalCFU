//
// Created by emanuele on 11/09/19.
//

#include "Achievement.h"

Achievement::Achievement(const std::string &text, const std::string &fontName, const string &filename) :
        texture(make_shared<sf::Texture>(sf::Texture{})) {
    font.loadFromFile(fontName);
    this->text = sf::Text(text, font, 40);
    texture->loadFromFile(filename);
    this->text.setFillColor(sf::Color(205, 164, 52));
}

void Achievement::render(sf::RenderWindow *rw) {
    if (!isRendering) {
        this->text.setPosition(rw->getView().getCenter().x - text.getLocalBounds().width / 2.0f,
                               rw->getView().getCenter().y + rw->getView().getSize().y / 2.0f - 80.0f);
        setPosition(this->text.getPosition().x - 40.0f, this->text.getPosition().y);
        rw->draw(*this);
        rw->draw(text);
    }
}


