//
// Created by madmag on 21/07/19.
//

#include "patrolBehaviour.h"

int patrolBehaviour::action(Player *p, Enemy *e) {
    if (p->getPosX() - e->getPosX() >= 0)
        e->walk(1);
    if (p->getPosX() - e->getPosX() < 0)
        e->walk(3);
    if (e->isCollisionLeft() || e->isCollisionRight()) {
        e->jump(100, e->getPosition().y);
    }
    return 0;
}

std::string patrolBehaviour::getName() {
    return name;
}