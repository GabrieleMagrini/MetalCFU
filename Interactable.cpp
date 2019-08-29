//
// Created by emanuele on 03/06/19.
//

#include "Interactable.h"



void Interactable::setCollision(bool v) {
    collision = v;
}

bool Interactable::getCollision() {
    return collision;
}

int Interactable::getHp() const {
    return hp;
}

void Interactable::setHp(int hp) {
    Interactable::hp = hp;
    if (this->hp < 0)
        this->hp = 0;
}