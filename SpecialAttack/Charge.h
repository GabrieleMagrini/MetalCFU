//
// Created by emanuele on 27/06/19.
//

#ifndef METALCFU_CHARGE_H
#define METALCFU_CHARGE_H

#include "SpecialAttack.h"
class Charge: public SpecialAttack {
    ~Charge() override = default;

    void doSpecial() override;
};


#endif //METALCFU_CHARGE_H
