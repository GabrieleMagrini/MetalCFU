//
// Created by emanuele on 03/06/19.
//

#include "MedKit.h"


int MedKit::use() {
    return healerPoints;
}

void MedKit::setHealerPoints(int healerPoints) {
    MedKit::healerPoints = healerPoints;
}
