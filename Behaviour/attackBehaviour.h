//
// Created by madmag on 21/07/19.
//

#ifndef METALCFU_ATTACKBEHAVIOUR_H
#define METALCFU_ATTACKBEHAVIOUR_H


#include "Behaviour.h"

class Enemy;

class attackBehaviour : public Behaviour {
public:
    attackBehaviour() {}

    virtual ~attackBehaviour() {}

    int action(Player *p, Enemy *e) override;
};


#endif //METALCFU_ATTACKBEHAVIOUR_H
