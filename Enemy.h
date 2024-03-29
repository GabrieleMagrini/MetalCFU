//
// Created by emanuele on 26/06/19.
//

#ifndef METALCFU_ENEMY_H
#define METALCFU_ENEMY_H

#include <memory>

#include "GameCharacter.h"
#include "Player.h"

class Behaviour;

using namespace std;

class Enemy : public GameCharacter {
public:
    Enemy(int hp, int x, int y, int s, Behaviour *b, Weapon *w, Usable *p, const string &filename = "", int mw = 1,
          int mu = 1,
          int sx = 0, int sy = 10, int sw = 0, int su = 0);

    ~Enemy() final;

    void Action(Player &p, Ammo &a);

    Behaviour *getBehaviour() const;

    void setBehaviour(Behaviour *behaviour);

    void checkBehaviour(Player &p);

private:
    int startPosX;
    int startPosY;
    Behaviour *behaviour;
};


#endif //METALCFU_ENEMY_H
