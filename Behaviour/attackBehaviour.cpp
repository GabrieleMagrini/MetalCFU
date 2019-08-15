//
// Created by madmag on 21/07/19.
//

#include "attackBehaviour.h"


int attackBehaviour::action(Player *p, Enemy *e) {
    e->getWeapon()->shoot(p->getPosition(), e->getPosition());
    e->move(p->getPosX(), p->getPosY());
    if (e->isCollisionLeft() || e->isCollisionRight())
        e->jump(100, e->getPosition().y);
    return 0;
}
