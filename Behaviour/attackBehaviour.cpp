//
// Created by madmag on 21/07/19.
//

#include "attackBehaviour.h"


int attackBehaviour::action(Player *p, Enemy *e) {
    e->getWeapon()->shoot(p->getPosition(), e->getPosition());
    e->move(p->getPosX(), p->getPosY());
    return 0;
}
