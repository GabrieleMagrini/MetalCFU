//
// Created by madmag on 29/07/19.
//

#ifndef METALCFU_SUICIDALBEHAVIOUR_H
#define METALCFU_SUICIDALBEHAVIOUR_H


#include "Behaviour.h"
#include "../Enemy.h"

class suicidalBehaviour : public Behaviour {
public:
    suicidalBehaviour() : Behaviour("Suicide") {}

    ~suicidalBehaviour() final = default;

    int action(Player &p, Enemy &e, Ammo &a) override;
};


#endif //METALCFU_SUICIDALBEHAVIOUR_H
