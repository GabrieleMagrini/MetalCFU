//
// Created by madmag on 29/07/19.
//

#include "suicidalBehaviour.h"


int suicidalBehaviour::action(Player &p, Enemy &e, Ammo &a) {

    if (e.isCollisionLeft() || e.isCollisionRight()) {
        e.setPosition(e.getPosition().x, e.getPosition().y - 48);
    } else if (p.getPosX() - e.getPosX() >= 0)
        e.walk(1);
    else
        e.walk(3);

    if (abs(e.getPosY() - p.getPosY()) <= 48 && abs(e.getPosX() - p.getPosX()) < 20) {
        p.getDamage(25);
        e.setHp(0);
    }
    return 0;
}