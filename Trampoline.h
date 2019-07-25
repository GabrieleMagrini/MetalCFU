//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_TRAMPOLINE_H
#define METALCFU_TRAMPOLINE_H


#include "Interactable.h"
#include "Player.h"

class Trampoline: public Interactable {
public:
    explicit Trampoline(int h,int r, int x, int y ,bool l):height(h), Interactable(x,y) , lift(l){};

    void liftUp(int height, Player *player);


private:
    int height;
    bool lift;
};


#endif //METALCFU_TRAMPOLINE_H
