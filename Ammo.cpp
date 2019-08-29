//
// Created by emanuele on 26/05/19.
//

#include "Ammo.h"
#include "Enemy.h"
#include "Terrain.h"
#include "Player.h"

Ammo::Ammo(int damage, int range, bool c, bool s) : damage(damage), range(range), terrainCollision(c), isShot(s),
                                                    gamecharacterCollision(c) {
    auto ammo = new sf::Texture();
    ammo->loadFromFile(
            "Sources/Pngs/weapon textures/ammo.png");
    this->setTexture(*ammo);
}


bool Ammo::operator==(const Ammo &a2) const {
    bool us = false;
    if (damage == a2.damage && isShot == a2.isShot && gamecharacterCollision == a2.gamecharacterCollision &&
        terrainCollision == a2.terrainCollision)
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

    if (isShot && (!gamecharacterCollision || !terrainCollision)) {
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

bool Ammo::checkCollision(std::vector<Enemy> &e, const std::vector<Terrain> &t, std::vector<Interactable> &I) {
    for (int i = 0; i < e.size(); i++)
        if (this->getGlobalBounds().intersects(e[i].getGlobalBounds())) {
            this->setGamecharacterCollision(true);
            e[i].getDamage(damage);
        }
    for (auto interactable:I)
        if (this->getGlobalBounds().intersects(interactable.getGlobalBounds())) {
            interactable.setHp(interactable.getHp() - damage);
            this->setInteractableCollision(true);
        }
    for (auto terrain:t)
        if (this->getGlobalBounds().intersects(terrain.getGlobalBounds()))
            this->setTerrainCollision(true);
    return false;
}

bool Ammo::checkPlayerCollision(Player &p, const std::vector<Terrain> &t, std::vector<Interactable> &I) {
    if (this->getGlobalBounds().intersects(p.getGlobalBounds())) {
        this->setGamecharacterCollision(true);
        p.getDamage(damage);
    }
    for (auto interactable:I)
        if (this->getGlobalBounds().intersects(interactable.getGlobalBounds())) {
            this->setInteractableCollision(true);
        }
    for (auto terrain:t)
        if (this->getGlobalBounds().intersects(terrain.getGlobalBounds()))
            this->setTerrainCollision(true);
    return false;
}

bool Ammo::isGamecharacterCollision() const {
    return gamecharacterCollision;
}

int Ammo::getDamage() const {
    return damage;
}

void Ammo::setDamage(int damage) {
    Ammo::damage = damage;
}

void Ammo::setGamecharacterCollision(bool gamecharacterCollision) {
    Ammo::gamecharacterCollision = gamecharacterCollision;
}

int Ammo::getRange() const {
    return range;
}

void Ammo::setRange(int range) {
    Ammo::range = range;
}

bool Ammo::isInteractableCollision() const {
    return interactableCollision;
}

void Ammo::setInteractableCollision(bool interactableCollision) {
    Ammo::interactableCollision = interactableCollision;
}


