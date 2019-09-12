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
    rectangleWeapon.setFillColor(sf::Color::Transparent);
    rectangleWeapon.setOutlineThickness(2);
    rectangleWeapon.setOutlineColor(sf::Color::Red);
    rectangleWeapon.setFillColor(sf::Color(255, 255, 255, 100));
    rectangleWeapon.setSize(
            sf::Vector2f(weaponAmmo.getLocalBounds().width + 2, weaponAmmo.getLocalBounds().height + 15));
    rectangleWeapon.setPosition(weaponAmmo.getPosition().x - 1, weaponAmmo.getPosition().y - 1);
    lives.setString("3");
    lives.setFont(font);
    lives.setPosition(10, 5);
    lives.setFillColor(sf::Color::Black);
    lives.setCharacterSize(15);

    lifeBorder.setSize(sf::Vector2f(300, 20));
    maxSizeX = 298;
    lifeBorder.setOutlineColor(sf::Color::Black);
    lifeBorder.setOutlineThickness(2);
    lifeBorder.setFillColor(sf::Color(255, 255, 255, 100));
    lifeBorder.setPosition(10, 10);

    life.setSize(sf::Vector2f(298, 18));
    life.setFillColor(sf::Color(50, 205, 50));
    life.setPosition(11, 21);
}

void Hud::render() {
    renderWin->draw(rectangleWeapon);
    renderWin->draw(weaponAmmo);
    renderWin->draw(lives);
    renderWin->draw(lifeBorder);
    renderWin->draw(life);
}

void Hud::update(Player &p, sf::View &view) {

    float top = view.getCenter().y - view.getSize().y / 2.0f;
    float left = view.getCenter().x - view.getSize().x / 2.0f;
    life.setSize(sf::Vector2f(p.getHp() * maxSizeX / 100.0f, life.getLocalBounds().height));
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
    weaponAmmo.setPosition(view.getCenter().x + view.getSize().x / 2 - weaponAmmo.getLocalBounds().width - 10,
                           top + 10);
    rectangleWeapon.setSize(
            sf::Vector2f(weaponAmmo.getLocalBounds().width + 5, weaponAmmo.getLocalBounds().height + 13));
    rectangleWeapon.setPosition(weaponAmmo.getPosition().x - 1, weaponAmmo.getPosition().y - 1);
    lives.setPosition(left + 20, top);

}
