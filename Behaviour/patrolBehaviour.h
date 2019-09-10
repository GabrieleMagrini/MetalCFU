//
// Created by madmag on 21/07/19.
//

#ifndef METALCFU_PATROLBEHAVIOUR_H
#define METALCFU_PATROLBEHAVIOUR_H


#include "Behaviour.h"
#include "../Enemy.h"

class patrolBehaviour : public Behaviour {
public:
    patrolBehaviour() : name("Patrol") {}

    ~patrolBehaviour() final = default;

    int action(Player &p, Enemy &e, Ammo &a) override;

    std::string getName() final;

private:
    std::string name;
};


#endif //METALCFU_PATROLBEHAVIOUR_H
