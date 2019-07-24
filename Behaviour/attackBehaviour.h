//
// Created by madmag on 21/07/19.
//

#ifndef METALCFU_ATTACKBEHAVIOUR_H
#define METALCFU_ATTACKBEHAVIOUR_H


#include "Behaviour.h"

class attackBehaviour : public Behaviour {
public:
    attackBehaviour() {}

    virtual ~attackBehaviour() {}

    int action(Player *p) override;
};


#endif //METALCFU_ATTACKBEHAVIOUR_H
