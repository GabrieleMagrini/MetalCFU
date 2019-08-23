//
// Created by madmag on 21/07/19.
//

#ifndef METALCFU_ATTACKBEHAVIOUR_H
#define METALCFU_ATTACKBEHAVIOUR_H


#include "Behaviour.h"
#include "../Enemy.h"


class attackBehaviour : public Behaviour {
public:
    attackBehaviour() : name("Attack") {}

    ~attackBehaviour() final = default;

    int action(Player *p, Enemy *e, Ammo &a) override;

    std::string getName() override;

private:
    std::string name;
};


#endif //METALCFU_ATTACKBEHAVIOUR_H
