//
// Created by madmag on 29/07/19.
//

#ifndef METALCFU_SUICIDALBEHAVIOUR_H
#define METALCFU_SUICIDALBEHAVIOUR_H


#include "Behaviour.h"
#include "../Enemy.h"

class suicidalBehaviour : public Behaviour {
public:
    suicidalBehaviour() : name("Suicide") {}

    virtual ~suicidalBehaviour() {}

    int action(Player *p, Enemy *e) override;

private:
    std::string name;
};


#endif //METALCFU_SUICIDALBEHAVIOUR_H
