//
// Created by emanuele on 25/06/19.
//

#include "PowerBarrel.h"

void PowerBarrel::improve(Weapon &w) {
    int percentual = static_cast<int>(improvement*w.getDamage()/100.f); //creating a percentual increment for the weapon

    w.setDamage(w.getDamage()+percentual);
}
