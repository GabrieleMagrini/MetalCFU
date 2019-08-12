//
// Created by emanuele on 26/05/19.
//

#include "Weapon.h"
#include "Ammo.h"
#include <math.h>

Weapon::Weapon(const Ammo &c, int d, int r, const Ammo &m, Texture *txt, bool k, int sy, int bs) : currentAmmo(c),
                                                                                                   damage(d),
                                                                                                   range(r),
                                                                                                   maxAmmo(m),
                                                                                                   activeLaser(false),
                                                                                                   collision(k),
                                                                                                   speedY(sy),
                                                                                                   bulletSpeed(bs) {
    if (txt != nullptr)
        setTexture(*txt);
}

Weapon::Weapon(int cur, int d, int r, int m, Texture *txt, int sy, int bs) : currentAmmo(cur), damage(d), range(r),
                                                                             maxAmmo(m),
                                                                             activeLaser(false), collision(false),
                                                                             speedY(sy), bulletSpeed(bs) {
    if (txt != nullptr)
        setTexture(*txt);
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
        while (!currentAmmo.getCollision())
            currentAmmo.move(bulletSpeed * cos(degrees), bulletSpeed * sin(degrees));
        return true;
    } else
        return false;
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
