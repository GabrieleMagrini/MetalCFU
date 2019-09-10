//
// Created by madmag on 21/07/19.
//

#include "patrolBehaviour.h"

int patrolBehaviour::action(Player &p, Enemy &e, Ammo &a) {
    if (abs(e.getPosX() - p.getPosX()) < 600) {
        if (e.isCollisionLeft() || e.isCollisionRight()) {
            e.setPosition(e.getPosition().x, e.getPosition().y - 48);
        } else if (p.getPosX() - e.getPosX() >= 0)
            e.walk(1);
        else
            e.walk(3);
    }
    return 0;
}