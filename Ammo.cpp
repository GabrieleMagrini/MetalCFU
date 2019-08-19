//
// Created by emanuele on 26/05/19.
//

#include "Ammo.h"
#include "GameCharacter.h"
#include "Terrain.h"

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

void Ammo::setTerrainCollision(bool v) {
    terrainCollision = v;
}

bool Ammo::getTerrainCollision() const {
    return terrainCollision;
}

void Ammo::shoot(sf::Vector2f posRif, sf::Vector2f posFin) {
    if (!gamecharacterCollision || !terrainCollision) {
        if (posFin.x - posRif.x >= 0)
            this->setPosition(this->getPosition().x + 1 * 40, this->getPosition().y);
        if (posFin.x - posRif.x < 0)
            this->setPosition(this->getPosition().x - 1 * 40, this->getPosition().y);
    }
}

bool Ammo::isIsShot() const {
    return isShot;
}

void Ammo::setIsShot(bool isShot) {
    Ammo::isShot = isShot;
}

bool Ammo::checkCollision(std::vector<GameCharacter> e, std::vector<Terrain> t) {
    for (auto character:e)
        if (this->getGlobalBounds().intersects(character.getGlobalBounds())) {
            this->setGamecharacterCollision(true);
            //character.setHp(character.getHp()-50);
        }
    for (auto terrain:t)
        if (this->getGlobalBounds().intersects(terrain.getGlobalBounds()))
            this->setTerrainCollision(true);
    return false;
}

bool Ammo::isGamecharacterCollision() const {
    return gamecharacterCollision;
}

void Ammo::setGamecharacterCollision(bool gamecharacterCollision) {
    Ammo::gamecharacterCollision = gamecharacterCollision;
}

