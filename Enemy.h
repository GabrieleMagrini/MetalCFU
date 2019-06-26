//
// Created by emanuele on 26/06/19.
//

#ifndef METALCFU_ENEMY_H
#define METALCFU_ENEMY_H

#include "GameCharacter.h"


class Enemy : public GameCharacter {
public:
    Enemy(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw = 1, int mu = 1, int ms = 10, int sw = 0,
          int su = 0, int steps = 50);

    ~Enemy() final = default;

    void Behaviour();

private:
    int startPosX;
    //int startposY;
    int steps;
};


#endif //METALCFU_ENEMY_H
