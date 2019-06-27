//
// Created by emanuele on 26/06/19.
//

#ifndef METALCFU_SPECIALATTACK_H
#define METALCFU_SPECIALATTACK_H


class SpecialAttack {
public:
    virtual ~SpecialAttack() = default;

    virtual void doSpecial() = 0;
};


#endif //METALCFU_SPECIALATTACK_H
