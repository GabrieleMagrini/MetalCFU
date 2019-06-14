//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_TRAMPOLINE_H
#define METALCFU_TRAMPOLINE_H


#include "Interactable.h"

class Trampoline: public Interactable {
public:
    explicit Trampoline(int h,int r, int x, int y):height(h), Interactable(x,y){};

    void liftUp(int  height);


private:
    int height;
};


#endif //METALCFU_TRAMPOLINE_H
