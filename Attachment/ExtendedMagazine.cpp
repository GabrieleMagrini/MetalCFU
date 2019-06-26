//
// Created by emanuele on 25/06/19.
//

#include "ExtendedMagazine.h"

void ExtendedMagazine::improve(Weapon &w) {

    if(w.getMaxAmmo().getQuantity()>0){
        int percentual = static_cast<int>(static_cast<float>(improvement)/ static_cast<float>(w.getMaxAmmo().getQuantity())*100);
        w.setMaxAmmo(w.getMaxAmmo().getQuantity()+percentual);
    }
}
