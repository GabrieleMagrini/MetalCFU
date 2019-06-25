//
// Created by emanuele on 25/06/19.
//

#include "PowerBarrel.h"

void PowerBarrel::Improve(Weapon &w) {
    w.setDamage(w.getDamage()+improveDamage);
}
