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

    Weapon(int c, int d, int r, const int m, bool k = false, int sy = 10,
           int bs = 10, const std::string &filename = "Sources/Pngs/weapon textures/sheetPistol.png",
           const std::string &wname = "");

    Weapon(int cur, int d, int r, int m, const std::string &filename = "Sources/Pngs/weapon textures/sheetPistol.png",
           const std::string &wname = "",
           int sy = 10, int bs = 10);

    Weapon(const Weapon &w) = default;

    int getCurrentAmmo();

    void setCurrentAmmo(int currentAmmo);

    int getDamage() const;

    void setDamage(int damage);

    int getRange() const;

    void setRange(int range);

    const int getMaxAmmo() const;

    void setMaxAmmo(int quantity);

    bool shoot();

    ~Weapon() override = default;

    bool isActiveLaser() const;

    void setActiveLaser(bool activeLaser);

    bool operator==(const Weapon &w1) const;

    float getPosX() const;

    float getPosY() const;

    void setCollision(bool v);

    bool getCollision();

    int getSpeedY() const;

    void setSpeedY(int speedY);

    int getBulletSpeed() const;

    void setBulletSpeed(int bulletSpeed);

    void setTextures(float xMouse, float xCharacter, bool isShooting);

    float getShootDirection() const;

    void setShootDirection(float shootDirection);

    const std::string &getName() const;

private:
    std::string name;
    int currentAmmo;
    int damage;
    int range;
    int maxAmmo;
    bool activeLaser;
    bool collision;
    int speedY;
    int bulletSpeed;
    float shootDirection;


    std::string filename;
    sf::Texture texture;
};


#endif //METALCFU_WEAPON_H
