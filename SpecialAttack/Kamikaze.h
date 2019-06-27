//
// Created by emanuele on 27/06/19.
//

#ifndef METALCFU_KAMIKAZE_H
#define METALCFU_KAMIKAZE_H

#include "SpecialAttack.h"

class Kamikaze: public SpecialAttack {

    ~Kamikaze() override = default;

    void doSpecial() override;
};


#endif //METALCFU_KAMIKAZE_H
