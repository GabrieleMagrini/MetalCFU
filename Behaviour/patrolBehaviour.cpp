//
// Created by madmag on 21/07/19.
//

#include "patrolBehaviour.h"

int patrolBehaviour::action(Player *p, Enemy *e) {
    e->move(-1, 0);
    return 0;
}