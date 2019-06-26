//
// Created by emanuele on 26/05/19.
//

#include "Weapon.h"
#include "Ammo.h"

Weapon::Weapon(const Ammo &c, int d, int r, const Ammo &m) : currentAmmo(c), damage(d), range(r), maxAmmo(m),
                                                             activeLaser(false) {}

Weapon::Weapon(int cur, int d, int r, int m) : currentAmmo(cur), damage(d), range(r), maxAmmo(m), activeLaser(false) {}

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

bool Weapon::shoot() {
    if (currentAmmo.getQuantity() > 0) {
        currentAmmo.setQuantity(currentAmmo.getQuantity() - 1);
        return true;
    } else
        return false;
}

Weapon::Weapon() : currentAmmo(0), damage(0), range(0), maxAmmo(0), activeLaser(false) {}

bool Weapon::isActiveLaser() const {
    return activeLaser;
}

void Weapon::setActiveLaser(bool activeLaser) {
    Weapon::activeLaser = activeLaser;
}

bool Weapon::operator==(const Weapon &w1) {
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
