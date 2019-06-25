//
// Created by emanuele on 25/06/19.
//

#include "PowerBarrel.h"

void PowerBarrel::improve(Weapon &w) {
    w.setDamage(w.getDamage()+improvement);
}
