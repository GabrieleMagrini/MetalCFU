//
// Created by emanuele on 26/06/19.
//
#include "WeaponFactory.h"

std::unique_ptr<Weapon> WeaponFactory::createWeapon(WeaponType w) {
    std::unique_ptr<Weapon> result;
    switch (w) {
        case WeaponType::pistol:
            result = std::unique_ptr<Weapon>(new Weapon{-1, 15, 4, -1});
            break;
        case WeaponType::M4 :
            result = std::unique_ptr<Weapon>(new Weapon{45, 40, 15, 300});
            break;
        case WeaponType::AK_47:
            result = std::unique_ptr<Weapon>(new Weapon{30, 50, 10, 250});
            break;
        case WeaponType::AWP:
            result = std::unique_ptr<Weapon>(new Weapon{5, 95, 30, 5});
            break;
    }
    return result;
}