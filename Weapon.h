//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_WEAPON_H
#define METALCFU_WEAPON_H

#include <SFML/Graphics.hpp>

#include "Ammo.h"

using namespace sf;

class Weapon : public sf::Sprite {
public:
    Weapon();

    Weapon(const Ammo &c, int d, int r, const Ammo &m, Texture *txt = nullptr);

    Weapon(int cur, int d, int r, int m, Texture *txt=nullptr);

    Weapon(const Weapon &w) = default;

    const Ammo &getCurrentAmmo() const;

    void setCurrentAmmo(const Ammo &currentAmmo);

    int getDamage() const;

    void setDamage(int damage);

    int getRange() const;

    void setRange(int range);

    const Ammo &getMaxAmmo() const;

    void setMaxAmmo(int quantity);

    bool shoot();

    ~Weapon() override = default;

    bool isActiveLaser() const;

    void setActiveLaser(bool activeLaser);

    bool operator==(const Weapon &w1) const;

    float getPosX() const;

    void setPosX(int posX);

    float getPosY() const;

    void setPosY(int posY);


private:
    Ammo currentAmmo;
    int damage;
    int range;
    Ammo maxAmmo;
    bool activeLaser;
};


#endif //METALCFU_WEAPON_H
