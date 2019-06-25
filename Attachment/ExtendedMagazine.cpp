//
// Created by emanuele on 25/06/19.
//

#include "ExtendedMagazine.h"

void ExtendedMagazine::improve(Weapon &w) {
    w.setMaxAmmo(w.getMaxAmmo().getQuantity()+improvement);
}
