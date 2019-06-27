//
// Created by emanuele on 27/06/19.
//

#ifndef METALCFU_BOSSATTACK_H
#define METALCFU_BOSSATTACK_H

#include "SpecialAttack.h"

class BossAttack: public SpecialAttack {
    ~BossAttack() override = default;

    void doSpecial() override;
};


#endif //METALCFU_BOSSATTACK_H
