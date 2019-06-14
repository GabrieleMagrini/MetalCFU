//
// Created by madmag on 12/06/19.
//

#ifndef METALCFU_PLAYER_H
#define METALCFU_PLAYER_H

#include "GameCharacter.h"

class Player: virtual public GameCharacter{
public:

    explicit Player(int l) : lives(l){}
    ~Player();

private:

    int lives;
};





#endif //METALCFU_PLAYER_H
