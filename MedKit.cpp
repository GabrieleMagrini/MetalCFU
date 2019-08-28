//
// Created by emanuele on 03/06/19.
//

#include "MedKit.h"


int MedKit::use(GameCharacter &g) {
    g.setHp(g.getHp() + data);

    if (g.getHp() > 100) {
        g.setHp(100);
    }
}
