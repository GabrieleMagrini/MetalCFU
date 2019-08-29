//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_AMMO_H
#define METALCFU_AMMO_H

#include <SFML/Graphics.hpp>
#include "Interactable.h"

class Enemy;

class Terrain;

class Player;


class Ammo : public sf::Sprite {
public:

    explicit Ammo(int damage = 1, int range = 1, bool c = false, bool s = false);

    Ammo(const Ammo &a) = default;

    bool operator==(const Ammo &a2) const;

    ~Ammo() final = default;

    int getDamage() const;

    void setDamage(int damage);

    void setTerrainCollision(bool v);

    bool getTerrainCollision() const;

    void shoot(sf::Vector2f posRif, sf::Vector2f posFin);

    bool isIsShot() const;

    void setIsShot(bool isShot);

    bool checkCollision(std::vector<Enemy> &e, const std::vector<Terrain> &t, std::vector<Interactable> &I);

    bool checkPlayerCollision(Player &p, const std::vector<Terrain> &t, std::vector<Interactable> &I);

    bool isGamecharacterCollision() const;

    void setGamecharacterCollision(bool gamecharacterCollision);

    int getRange() const;

    void setRange(int range);

    bool isInteractableCollision() const;

    void setInteractableCollision(bool interactableCollision);

private:
    int damage;
    int range;
    bool terrainCollision;
    bool isShot;
    bool gamecharacterCollision;
    bool interactableCollision;
};


#endif //METALCFU_AMMO_H
