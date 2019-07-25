//
// Created by emanuele on 03/06/19.
//

#include "Trampoline.h"
#include "Player.h"
#include "Collision.h"

//The function is called until the bool value "liftUp" get value "false"
void Trampoline::liftUp(int height, Player *player) {

    if (Collision::PixelPerfectTest(*player, *this))
        player->setSpeedY(player->getSpeedY() + height);

}
