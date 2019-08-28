//
// Created by emanuele on 14/06/19.
//

#include "Granade.h"

int Granade::use(GameCharacter &g) {
    //TODO trow granade
    move(5, 0);
    return 0;
}

Granade::Granade(int d, int expTime) : Usable(d), explosionTime(expTime) {

}

int Granade::getExplosionTime() const {
    return explosionTime;
}

void Granade::setExplosionTime(int explosionTime) {
    Granade::explosionTime = explosionTime;
}
