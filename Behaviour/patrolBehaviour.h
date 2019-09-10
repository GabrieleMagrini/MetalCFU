//
// Created by madmag on 21/07/19.
//

#ifndef METALCFU_PATROLBEHAVIOUR_H
#define METALCFU_PATROLBEHAVIOUR_H


#include "Behaviour.h"
#include "../Enemy.h"

class patrolBehaviour : public Behaviour {
public:
    patrolBehaviour() : Behaviour("Patrol") {}

    ~patrolBehaviour() final = default;

    int action(Player &p, Enemy &e, Ammo &a) override;

};


#endif //METALCFU_PATROLBEHAVIOUR_H
