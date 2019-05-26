//
// Created by emanuele on 26/05/19.
//

#include "Weapon.h"
#include "Ammo.h"

Weapon::Weapon(const Ammo& c, int d, int r,const Ammo& m):currentAmmo(c), damage(d), range(r),maxAmmo(m) {}

Weapon::Weapon(int cur, int d, int r, int m): currentAmmo(cur), damage(d),range(r),maxAmmo(m) {}

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

void Weapon::setMaxAmmo(const Ammo &maxAmmo) {
    Weapon::maxAmmo = maxAmmo;
}



