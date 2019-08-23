//
// Created by madmag on 21/07/19.
//

#include "patrolBehaviour.h"

int patrolBehaviour::action(Player *p, Enemy *e, Ammo &a) {

    if (e->isCollisionLeft() || e->isCollisionRight()) {
        e->setPosition(e->getPosition().x, e->getPosition().y - 48);
    } else if (p->getPosX() - e->getPosX() >= 0)
        e->walk(1);
    else if (p->getPosX() - e->getPosX() < 0)
        e->walk(3);

    return 0;
}

std::string patrolBehaviour::getName() {
    return name;
}