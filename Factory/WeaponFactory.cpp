//
// Created by emanuele on 26/06/19.
//
#include "WeaponFactory.h"

std::unique_ptr<Weapon> WeaponFactory::createWeapon(WeaponType w) {
    std::unique_ptr<Weapon> result;
    switch (w) {
        case WeaponType::pistol:
            result = std::unique_ptr<Weapon>(
                    new Weapon{0, 15, 10, -1, "Sources/Pngs/weapon textures/sheetPistol.png", "pistol"});
            break;
        case WeaponType::M4 :
            result = std::unique_ptr<Weapon>(
                    new Weapon{45, 40, 20, 300, "Sources/Pngs/weapon textures/sheetM4.png", "M4"});
            break;
        case WeaponType::AK_47:
            result = std::unique_ptr<Weapon>(
                    new Weapon{30, 50, 25, 250, "Sources/Pngs/weapon textures/sheetAK.png", "AK-47"});
            break;
        case WeaponType::AWP:
            result = std::unique_ptr<Weapon>(
                    new Weapon{5, 95, 50, 5, "Sources/Pngs/weapon textures/sheetAWP.png", "AWP"});
            break;
    }
    return result;
}