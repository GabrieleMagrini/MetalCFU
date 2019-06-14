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

bool Weapon::shoot() {
    if(currentAmmo.getQuantity()>0){
        currentAmmo.setQuantity(currentAmmo.getQuantity()-1);
        return true;
    }
    else
        return false;
}

Weapon::Weapon(WeaponType type) {
    switch (type) {
        default: //pistol
            damage=15;
            range=4;
            maxAmmo=Ammo{-1};
            currentAmmo=Ammo{-1};
            break;
        case WeaponType::M4 :
            damage=40;
            range=15;
            maxAmmo=Ammo{300};
            currentAmmo=Ammo{45};
            break;
        case WeaponType::AK_47:
            damage=50;
            range=10;
            maxAmmo=Ammo{250};
            currentAmmo=Ammo{30};
            break;
        case WeaponType ::AWP:
            damage=95;
            range=30;
            maxAmmo=Ammo{20};
            currentAmmo=Ammo{5};
    }
}


