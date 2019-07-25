//
// Created by madmag on 21/07/19.
//

#ifndef METALCFU_PATROLBEHAVIOUR_H
#define METALCFU_PATROLBEHAVIOUR_H


#include "Behaviour.h"

class patrolBehaviour : public Behaviour {
public:
    patrolBehaviour() {}

    virtual ~patrolBehaviour() {}

    int action(Player *p, Enemy *e) override;
};


#endif //METALCFU_PATROLBEHAVIOUR_H
