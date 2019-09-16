//
// Created by emanuele on 03/06/19.
//

#include "MedKit.h"


void MedKit::use(GameCharacter &g) {
    int temp = g.getHp() + data;
    if (temp > 100)
        temp = 100;
    g.setHp(temp);
}
