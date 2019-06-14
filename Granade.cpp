//
// Created by emanuele on 14/06/19.
//

#include "Granade.h"

int Granade::use() {
    //TODO trow granade
    return 0;
}

int Granade::getDamage() const {
    return damage;
}

void Granade::setDamage(int damage) {
    Granade::damage = damage;
}
