//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_WEAPON_H
#define METALCFU_WEAPON_H

#include "Ammo.h"

enum class WeaponType{AK_47, M4, AWP };

class Weapon {
public:
    Weapon(const Ammo& c, int d, int r,const Ammo& m);
    explicit Weapon(WeaponType type);
    Weapon(int cur,int d,int r,int m);

    Weapon(const Weapon& w)= default;

    const Ammo &getCurrentAmmo() const;

    void setCurrentAmmo(const Ammo &currentAmmo);

    int getDamage() const;

    void setDamage(int damage);

    int getRange() const;

    void setRange(int range);

    const Ammo &getMaxAmmo() const;

    void setMaxAmmo(const Ammo &maxAmmo);

    bool shoot();

    virtual ~Weapon() = default;

private:
    Ammo currentAmmo;
    int damage;
    int range;
    Ammo maxAmmo;
};


#endif //METALCFU_WEAPON_H
