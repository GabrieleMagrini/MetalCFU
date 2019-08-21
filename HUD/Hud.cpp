//
// Created by emanuele on 16/08/19.
//

#include "Hud.h"

Hud::Hud(std::shared_ptr<sf::RenderWindow> renderWin, const sf::Font &font) : renderWin(std::move(renderWin)) {
    weaponAmmo.setString("name    --/--");
    weaponAmmo.setPosition(this->renderWin->getSize().x - weaponAmmo.getLocalBounds().width, 10);
    weaponAmmo.setFillColor(sf::Color::Red);
    weaponAmmo.setFont(font);
    weaponAmmo.setCharacterSize(24);

    lives.setString("3");
    lives.setFont(font);
    lives.setPosition(10, 5);
    lives.setFillColor(sf::Color::Black);
    lives.setCharacterSize(15);

    lifeBorder.setSize(sf::Vector2f(300, 20));
    lifeBorder.setOutlineColor(sf::Color::Black);
    lifeBorder.setPosition(10, 10);

    life.setSize(sf::Vector2f(298, 18));
    life.setFillColor(sf::Color::Red);
    life.setPosition(11, 21);
}

void Hud::render() {
    renderWin->draw(weaponAmmo);
    renderWin->draw(lives);
    renderWin->draw(lifeBorder);
    renderWin->draw(life);
}

void Hud::update(Player &p, sf::View &view) {

    float top = view.getCenter().y - view.getSize().y / 2.0f;
    float left = view.getCenter().x - view.getSize().x / 2.0f;
    life.setSize(sf::Vector2f(p.getHp() * life.getSize().x / 100, life.getLocalBounds().height));
    stringstream ss;
    if (p.getWeapon()->getMaxAmmo() == -1) {
        ss << p.getWeapon()->getName() << "   " << "--/--";
    } else {
        ss << p.getWeapon()->getName() << "   " << p.getWeapon()->getCurrentAmmo().size() << "/"
           << p.getWeapon()->getMaxAmmo();
    }
    weaponAmmo.setString(ss.str());
    ss.str("");

    ss << "Lives: " << p.getLives();
    lives.setString(ss.str());

    lifeBorder.setPosition(left + 10, top + 20);
    life.setPosition(left + 11, top + 21);
    weaponAmmo.setPosition(view.getCenter().x - weaponAmmo.getLocalBounds().width / 2.0f, top + 10);
    lives.setPosition(left + 20, top);

}
