//
// Created by emanuele on 25/06/19.
//

#include "ExtendedMagazine.h"

void ExtendedMagazine::improve(Weapon &w) {

    if(w.getMaxAmmo().getQuantity()>0){
        int percentual = static_cast<int>(improvement*w.getMaxAmmo().getQuantity()/100.f);
        w.setMaxAmmo(w.getMaxAmmo().getQuantity()+percentual);
    }
}
