//
// Created by emanuele on 23/05/19.
//

#ifndef METALCFUREPO_GAMECHARACTER_H
#define METALCFUREPO_GAMECHARACTER_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>

#include "Weapon.h"
#include "Usable.h"
#include "Inventory.h"

using namespace sf;

class GameCharacter : public Sprite {
public:
    GameCharacter(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw = 4, int mu = 4, int sx = 10, int sy = -10,
                  int sw = 0,
                  int su = 4, bool c = false, const std::string &textDirectory = "");

    ~GameCharacter() override = default;

    int getHp() const;

    void setHp(int hp);

    float getPosX() const;

    float getPosY() const;

    int getStrenght() const;

    void setStrenght(int strenght);

    int getSpeedX() const;

    void setSpeedX(int SpeedX);

    int getSpeedY() const;

    void setSpeedY(int SpeedY);

    void teleport(float x, float y);

    void walk(int direction);

    Weapon *getWeapon();

    Weapon *setWeapon(Weapon *weapon);

    Usable *getUsable(int idx);

    Usable *setUsable(Usable *usable);

    int getDimWeapon() const;

    void setDimWeapon(int dw);

    int getDimUsable() const;

    void setDimUsable(int ud);

    Weapon *removeWeapon(int idx);

    Usable *removeUsable(int idx);

    int getSelectedWeapon() const;

    const Inventory<Weapon> &getWeaponInventory() const;

    void setWeaponInventory(const Inventory<Weapon> &weaponInventory);

    const Inventory<Usable *> &getUsableInventory() const;

    void setUsableInventory(const Inventory<Usable *> &usableInventory);


    void setSelectedWeapon(int selectedWeapon);

    void releaseInventory(Inventory<Weapon> &wi, Inventory<Usable *> &ui);

    static bool isTwoGameCharacterNearby(GameCharacter *gc1, GameCharacter *gc2);

    void getDamage(unsigned int damage);

    void fight(GameCharacter *enemy);

    void useUsable(int invIdx);

    void setCollisionUp(bool v);

    bool isCollisionUp();

    void setCollisionDown(bool v);

    bool isCollisionDown();

    void jump(float height, float startY);

    bool isJumping() const;

    void setJumping(bool j);

    bool isCollisionLeft() const;

    void setCollisionLeft(bool collisionLeft);

    bool isCollisionRight() const;

    void setCollisionRight(bool collisionRight);

    vector<Vector2f> &getAimInitial();

    void setAimInitial(vector<Vector2f> &aimInitial);

    vector<Vector2f> &getAimFinal();

    void setAimFinal(vector<Vector2f> &aimFinal);

protected:
    int HP;
    int strenght;
    Inventory<Weapon> weaponInventory;
    Inventory<Usable *> usableInventory;
    int selectedWeapon;
    int selectedUsable;
    int SpeedX;
    int SpeedY;
    bool collisionUp;
    bool collisionDown;
    bool collisionLeft;
    bool collisionRight;
    bool jumping;
    vector<Vector2f> aimInitial;
    vector<Vector2f> aimFinal;

};


#endif //METALCFUREPO_GAMECHARACTER_H
