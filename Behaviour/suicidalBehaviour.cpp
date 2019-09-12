//
// Created by madmag on 29/07/19.
//

#include "suicidalBehaviour.h"


int suicidalBehaviour::action(Player &p, Enemy &e, Ammo &a) {
    e.move(p.getPosX(), p.getPosY());
    if (abs(e.getPosY() - p.getPosY()) <= 1 && abs(e.getPosX() - p.getPosX()) < 3) {
        p.setHp(p.getHp() - (e.getHp() * 2));
        e.setHp(0);
    }
    return 0;
}