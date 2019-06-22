//
// Created by madmag on 22/06/19.
//

#ifndef METALCFU_BARRIER_H
#define METALCFU_BARRIER_H


#include "Interactable.h"

class Barrier : public Interactable {

     explicit Barrier(int x = 100,int y = 10,int r = 100) : resistancePoint(r),Interactable(x,y) {}

private:
    int resistancePoint;
};


#endif //METALCFU_BARRIER_H
