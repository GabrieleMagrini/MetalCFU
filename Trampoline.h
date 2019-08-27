//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_TRAMPOLINE_H
#define METALCFU_TRAMPOLINE_H


#include "Interactable.h"
#include "Player.h"

class Trampoline: public Interactable {
public:
    explicit Trampoline(int h = 300);

    void liftUp(Player *player);


private:
    int height;
};


#endif //METALCFU_TRAMPOLINE_H
