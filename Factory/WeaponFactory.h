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
    WeaponFactory() = default;

    virtual ~WeaponFactory() = default;

    virtual std::unique_ptr<Weapon> createWeapon(WeaponType w);

};




#endif //METALCFU_WEAPONFACTORY_H
