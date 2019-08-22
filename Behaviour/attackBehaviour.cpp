//
// Created by madmag on 21/07/19.
//

#include "attackBehaviour.h"


int attackBehaviour::action(Player *p, Enemy *e, Ammo &a) {
    a = e->getWeapon()->shoot();
    return 0;
}

std::string attackBehaviour::getName() {
    return name;
}