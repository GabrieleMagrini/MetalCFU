//
// Created by emanuele on 26/05/19.
//

#include "Weapon.h"

Weapon::Weapon(int cur, int d, int r, int m, const std::string &filename, const std::string &wname, int sy, int bs)
        : currentAmmo(cur, Ammo(d, r * 100)), damage(d),
          range(r),
          maxAmmo(m),
          activeLaser(false),
          collision(false),
          speedY(sy), bulletSpeed(bs),
          filename(filename), shootDirection(0), name(wname), shooting(false) {

    texture.loadFromFile(this->filename);
    setTexture(this->texture);
}

std::vector<Ammo> Weapon::getCurrentAmmo() {
    return currentAmmo;
}

void Weapon::setCurrentAmmo(const unsigned long &quantity) {
    currentAmmo = std::vector<Ammo>{quantity, Ammo(getDamage())};
}

int Weapon::getDamage() const {
    return damage;
}

void Weapon::setDamage(int damage) {
    Weapon::damage = damage;
}

int Weapon::getRange() const {
    return range;
}

void Weapon::setRange(int range) {
    Weapon::range = range;
}

const int &Weapon::getMaxAmmo() const {
    return maxAmmo;
}

void Weapon::setMaxAmmo(const int quantity) {
    maxAmmo = quantity;
}

Ammo Weapon::shoot() {
    Ammo a;
    if (name != "pistol") {
        if (currentAmmo.size() > 0) {
            currentAmmo[0].setIsShot(true);
            currentAmmo[0].setPosition(getPosition());
            a = currentAmmo[0];
            currentAmmo.erase(currentAmmo.begin());
            return a;
            // float angolarCoefficient = (posFin.y - posRif.y) / (posFin.x - posRif.x);
            //auto degrees = static_cast<double>(atan(angolarCoefficient));
            //while (!currentAmmo.getCollision() || (abs(currentAmmo.getPosition().x - posRif.x) > range ||abs(currentAmmo.getPosition().y - posRif.y) > range))
            //if(currentAmmo.getCollision()|| (abs(currentAmmo.getPosition().x - posRif.x) > range ||abs(currentAmmo.getPosition().y - posRif.y) > range))
            //   currentAmmo.setPosition(this->getPosition());

        }
    } else {
        a = Ammo(damage, range, false, true);
        a.setPosition(getPosition());
    }
    return a;
}

Weapon::Weapon() : currentAmmo(0), damage(0), range(0), maxAmmo(0), activeLaser(false), collision(false), speedY(10),
                   bulletSpeed(10), shootDirection(0), shooting(false) {}

bool Weapon::isActiveLaser() const {
    return activeLaser;
}

void Weapon::setActiveLaser(bool activeLaser) {
    Weapon::activeLaser = activeLaser;
}

bool Weapon::operator==(const Weapon &w1) const {
    bool us = true;
    if (range != w1.range)
        us = false;
    else if (damage != w1.damage)
        us = false;
    else if (maxAmmo != w1.maxAmmo)
        us = false;
    else if (!(currentAmmo == w1.currentAmmo))
        us = false;
    else if (activeLaser != w1.activeLaser)
        us = false;
    return us;
}

float Weapon::getPosX() const {
    return getPosition().x;
}

float Weapon::getPosY() const {
    return getPosition().y;
}


void Weapon::setCollision(bool v) {
    collision = v;
}

bool Weapon::getCollision() {
    return collision;
}

int Weapon::getSpeedY() const {
    return speedY;
}

void Weapon::setSpeedY(int speedY) {
    Weapon::speedY = speedY;
}

int Weapon::getBulletSpeed() const {
    return bulletSpeed;
}

void Weapon::setBulletSpeed(int bulletspeed) {
    Weapon::bulletSpeed = bulletspeed;
}

/**
 * function that update the texture, in base of the position of the player and the mouse, and in base of weapon is shooting
 * @param xMouse   coord x of the mouse
 * @param xCharacter coord x of the Character
 * @param isShooting bool if weapon is shooting
 */
void Weapon::setTextures(float xMouse, float xCharacter) {
    //funzionante per ora solo con pistola
    IntRect ir;
    setTexture(texture);
    if (xMouse > xCharacter) {
        if (shooting)
            ir = IntRect(texture.getSize().x / 2, 0, texture.getSize().x / 2, texture.getSize().y / 2);

        else
            ir = IntRect(0, 0, texture.getSize().x / 2, texture.getSize().y / 2);

        setPosition(xCharacter + getLocalBounds().width / 4.f - getLocalBounds().width / 2, this->getPosition().y);
    } else {
        if (shooting)

            ir = IntRect(texture.getSize().x / 2, texture.getSize().y / 2, texture.getSize().x / 2,
                         texture.getSize().y / 2);
        else
            ir = IntRect(0, texture.getSize().y / 2, texture.getSize().x / 2, texture.getSize().y / 2);
        setPosition(xCharacter + getLocalBounds().width / 4.f - getLocalBounds().width, this->getPosition().y);
    }

    this->setTextureRect(ir);
}

float Weapon::getShootDirection() const {
    return shootDirection;
}

void Weapon::setShootDirection(float shootDirection) {
    Weapon::shootDirection = shootDirection;
}

const std::string &Weapon::getName() const {
    return name;
}

bool Weapon::isShoot() const {
    return shooting;
}

void Weapon::setShoot(bool shoot) {
    Weapon::shooting = shoot;
}
