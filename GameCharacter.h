//
// Created by emanuele on 23/05/19.
//

#ifndef METALCFUREPO_GAMECHARACTER_H
#define METALCFUREPO_GAMECHARACTER_H

#include <memory>
#include "Weapon.h"


class GameCharacter {
public:
    GameCharacter(int hp, int x, int y, int s,Weapon* w, int ms);

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

    const std::shared_ptr<Weapon> &getWeapon() const;

    void setWeapon(Weapon* weapon);


private:
    int HP;
    int posX;
    int posY;
    int strenght;
    Weapon* weapon;
    int movementSpeed;

};


#endif //METALCFUREPO_GAMECHARACTER_H
