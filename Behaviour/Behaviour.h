//
// Created by madmag on 13/07/19.
//

#ifndef METALCFU_BEHAVIOUR_H
#define METALCFU_BEHAVIOUR_H


#include "../Player.h"

class Enemy;

class Behaviour {
public:
    virtual ~Behaviour() {}

    virtual int action(Player *p, Enemy *e) = 0;
};



#endif //METALCFU_BEHAVIOUR_H
