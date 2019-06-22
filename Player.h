//
// Created by madmag on 12/06/19.
//

#ifndef METALCFU_PLAYER_H
#define METALCFU_PLAYER_H

#include "GameCharacter.h"
#include "Inventory.h"

class Player: virtual public GameCharacter{
public:

    explicit Player(int l,Weapon *w, int hp=100,int s=20,int x=10,int y=10) : lives(l), GameCharacter(hp,x,y,s,w,nullptr){}
    ~Player()override = default;

    void lootPickUp();
private:

    int lives;
};




#endif //METALCFU_PLAYER_H
