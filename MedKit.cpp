//
// Created by emanuele on 03/06/19.
//

#include "MedKit.h"

void MedKit::use(GameCharacter* g) {
    g->setHp(g->getHp()+healerPoints);
}

int MedKit::getHealerPoints() const {
    return healerPoints;
}

void MedKit::setHealerPoints(int healerPoints) {
    MedKit::healerPoints = healerPoints;
}
