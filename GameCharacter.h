//
// Created by emanuele on 23/05/19.
//

#ifndef METALCFUREPO_GAMECHARACTER_H
#define METALCFUREPO_GAMECHARACTER_H

#include <memory>
#include "Weapon.h"
#include "Usable.h"
#include <vector>


class GameCharacter {
public:
    GameCharacter(int hp, int x, int y, int s, int ms);

    ~GameCharacter();


public:
    int getHp() const;

    void setHp(int hp);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    int getStrenght() const;

    void setStrenght(int strenght);

    int getMovementSpeed() const;

    void setMovementSpeed(int movementSpeed);

    void move(int x, int y);

    const  Weapon* getWeapon(int idx) const;

    bool setWeapon(Weapon* weapon);

    Usable *getUsable(int idx) const;

    bool setUsable(Usable *usable);

    int getMaxWeapon() const;

    void setMaxWeapon(int maxWeapon);

    Weapon* removeWeapon(int idx);

    Usable* removeUsable(int idx);

    void releaseInventory(std::vector<Weapon*>& wi, std::vector<Usable*>& ui);

private:
    int HP;
    int posX;
    int posY;
    int strenght;
    std::vector<Weapon*> weaponInventory;
    std::vector<Usable*> usableInventory;
    int maxWeapon;
    int maxUsable;
    int movementSpeed;

};


#endif //METALCFUREPO_GAMECHARACTER_H
