//
// Created by emanuele on 26/06/19.
//

#ifndef METALCFU_WEAPONFACTORY_H
#define METALCFU_WEAPONFACTORY_H

#include "../Weapon.h"
#include <memory>

enum class WeaponType {
    pistol, AK_47, M4, AWP
};

class WeaponFactory {
public:
    WeaponFactory();

    virtual ~WeaponFactory();

    virtual std::unique_ptr<Weapon> createWeapon(WeaponType &w);

};

std::unique_ptr<Weapon> WeaponFactory::createWeapon(WeaponType &w) {
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


#endif //METALCFU_WEAPONFACTORY_H
