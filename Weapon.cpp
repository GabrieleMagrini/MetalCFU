//
// Created by emanuele on 26/05/19.
//

#include "Weapon.h"


Weapon::Weapon(const Ammo &c, int d, int r, const Ammo &m, bool k, int sy, int bs, const std::string &filename)
        : currentAmmo(c),
          damage(d),
          range(r),
          maxAmmo(m),
          activeLaser(false),
          collision(k),
          speedY(sy),
          bulletSpeed(bs), filename(std::move(filename)) {
    texture.loadFromFile(this->filename);
    setTexture(this->texture);
    setTextureRect(IntRect(0, 0, 24, 24));//solo per pistole
}

Weapon::Weapon(int cur, int d, int r, int m, const std::string &filename, int sy, int bs)
        : currentAmmo(cur), damage(d),
          range(r),
          maxAmmo(m),
          activeLaser(false),
          collision(false),
          speedY(sy), bulletSpeed(bs),
          filename(std::move(filename)) {
    texture.loadFromFile(this->filename);
    setTexture(this->texture);
    setTextureRect(IntRect(0, 0, 24, 24));//solo per pistole
}

const Ammo &Weapon::getCurrentAmmo() const {
    return currentAmmo;
}

void Weapon::setCurrentAmmo(const Ammo &currentAmmo) {
    Weapon::currentAmmo = currentAmmo;
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

const Ammo &Weapon::getMaxAmmo() const {
    return maxAmmo;
}

void Weapon::setMaxAmmo(const int quantity) {
    Weapon::maxAmmo.setQuantity(quantity);
}

bool Weapon::shoot(Vector2f posRif, Vector2f posFin) {
    if (currentAmmo.getQuantity() > 0) {
        currentAmmo.setQuantity(currentAmmo.getQuantity() - 1);
        float angolarCoefficient = static_cast<float> (posFin.y - posRif.y) / static_cast<float>(posFin.x - posRif.x);
        double degrees = atan(angolarCoefficient);
        if (posFin.x - posRif.x < 0)
            bulletSpeed = abs(bulletSpeed);
        else
            bulletSpeed = -abs(bulletSpeed);
        while (!currentAmmo.getCollision() || (abs(currentAmmo.getPosition().x - posRif.x) > range ||
                                               abs(currentAmmo.getPosition().y - posRif.y) > range))
            currentAmmo.move(bulletSpeed * cos(degrees), bulletSpeed * sin(degrees));
        return false;
    } else
        return true;
}

Weapon::Weapon() : currentAmmo(0), damage(0), range(0), maxAmmo(0), activeLaser(false), collision(false), speedY(10),
                   bulletSpeed(10) {}

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
    else if (!(maxAmmo == w1.maxAmmo))
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

void Weapon::setTextures(const std::string &direction, bool isShooting) {

    IntRect ir;
    if (direction == "right") {
        if (isShooting)
            ir = IntRect(25, 0, 50, 25);
        else
            ir = IntRect(0, 0, 24, 24);
    } else {
        if (isShooting)

            ir = IntRect(25, 25, 50, 50);
        else
            ir = IntRect(0, 25, 25, 50);
    }
    setTextureRect(ir);
}
