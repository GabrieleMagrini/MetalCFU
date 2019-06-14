//
// Created by emanuele on 03/06/19.
//

#include "Trampoline.h"
#include "Player.h"
 //The function is called until the bool value "liftUp" get value "false"
bool Trampoline::liftUp(int height,Player *player) {

    bool valid;

        if (player->getPosY() == height)
            valid = false;
        else {
            player->setPosY(player->getPosY()+player->getMovementSpeed());
            valid = true;
        }

     return valid;
}
