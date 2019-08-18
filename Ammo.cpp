//
// Created by emanuele on 26/05/19.
//

#include "Ammo.h"

int Ammo::getQuantity() const {
    return quantity;
}

void Ammo::setQuantity(int quantity) {
    Ammo::quantity = quantity;
}

bool Ammo::operator==(const Ammo &a2) const{
    bool us = false;
    if (quantity == a2.quantity)
        us = true;
    return us;
}

void Ammo::setCollision(bool v) {
    collision = v;
}

bool Ammo::getCollision() const {
    return collision;
}

void Ammo::shoot(sf::Vector2f posRif, sf::Vector2f posFin) {
    if (posFin.x - posRif.x >= 0)
        this->setPosition(this->getPosition().x + 1 * 40, this->getPosition().y);
    if (posFin.x - posRif.x < 0)
        this->setPosition(this->getPosition().x - 1 * 40, this->getPosition().y);
}

bool Ammo::isIsShot() const {
    return isShot;
}

void Ammo::setIsShot(bool isShot) {
    Ammo::isShot = isShot;
}
