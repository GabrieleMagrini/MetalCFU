//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_WEAPON_H
#define METALCFU_WEAPON_H

#include <SFML/Graphics.hpp>
#include <cmath>

#include "Ammo.h"

using namespace sf;

class Weapon : public sf::Sprite {
public:
    Weapon();

    Weapon(const Ammo &c, int d, int r, const Ammo &m, bool k = false, int sy = 10,
           int bs = 10, const std::string &filename = "Sources/Pngs/weapon textures/sheetPistol.png");

    Weapon(int cur, int d, int r, int m, Texture *txt = nullptr, int sy = 10, int bs = 10);

    Weapon(const Weapon &w) = default;

    const Ammo &getCurrentAmmo() const;

    void setCurrentAmmo(const Ammo &currentAmmo);

    int getDamage() const;

    void setDamage(int damage);

    int getRange() const;

    void setRange(int range);

    const Ammo &getMaxAmmo() const;

    void setMaxAmmo(int quantity);

    bool shoot(sf::Vector2f posFin, sf::Vector2f posRif);

    ~Weapon() override = default;

    bool isActiveLaser() const;

    void setActiveLaser(bool activeLaser);

    bool operator==(const Weapon &w1) const;

    float getPosX() const;

    void setPosX(int posX);

    float getPosY() const;

    void setPosY(int posY);

    void setCollision(bool v);

    bool getCollision();

    int getSpeedY() const;

    void setSpeedY(int speedY);

    int getBulletSpeed() const;

    void setBulletSpeed(int bulletSpeed);

    void setTextures(const std::string &direction, bool isShooting);
private:
    Ammo currentAmmo;
    int damage;
    int range;
    Ammo maxAmmo;
    bool activeLaser;
    bool collision;
    int speedY;
    int bulletSpeed;
    std::string filename;
    sf::Texture texture;
};


#endif //METALCFU_WEAPON_H
