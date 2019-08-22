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

    virtual ~attackBehaviour() {}

    int action(Player *p, Enemy *e) override;

    std::string getName();

private:
    std::string name;
};


#endif //METALCFU_ATTACKBEHAVIOUR_H
