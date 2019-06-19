//
// Created by emanuele on 23/05/19.
//

#ifndef METALCFUREPO_GAMECHARACTER_H
#define METALCFUREPO_GAMECHARACTER_H
#include <vector>
#include <memory>

#include "Weapon.h"
#include "Usable.h"
#include "Inventory.h"


class GameCharacter {
public:
    GameCharacter(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw = 4, int mu = 4, int ms = 10, int sw = 0);

    virtual ~GameCharacter() = default;


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

    const Weapon *getWeapon() const;

    Weapon * setWeapon(Weapon *weapon);

    Usable *getUsable(int idx) const;

    bool setUsable(Usable *usable);

    int getMaxWeapon() const;

    void setMaxWeapon(int maxWeapon);

    int getDimUsable() const;

    void setMaxUsable(int maxUsable);

    Weapon* removeWeapon(int idx);

    Usable* removeUsable(int idx);

    int getSelectedWeapon() const;

    const std::vector<Weapon *> &getWeaponInventory() const;

    void setWeaponInventory(const std::vector<Weapon *> &weaponInventory);

    const std::vector<Usable *> &getUsableInventory() const;

    void setUsableInventory(const std::vector<Usable *> &usableInventory);


    void setSelectedWeapon(int selectedWeapon);

    void releaseInventory(std::vector<Weapon*>& wi, std::vector<Usable*>& ui);

    static bool isTwoGameCharacterNearby(GameCharacter* gc1,GameCharacter* gc2);

    void getDamage(unsigned int damage);

    void fight(GameCharacter* enemy);

    void useUsable(int invIdx);

    Usable *changeUsable(Usable *usable, int idx);

private:
    int HP;
    int posX;
    int posY;
    int strenght;
    Inventory<Weapon> weaponInventory;
    Inventory<Usable*> usableInventory;
    int selectedWeapon;
    int movementSpeed;

};


#endif //METALCFUREPO_GAMECHARACTER_H
