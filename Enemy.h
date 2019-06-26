//
// Created by emanuele on 26/06/19.
//

#ifndef METALCFU_ENEMY_H
#define METALCFU_ENEMY_H

#include "GameCharacter.h"

enum class EnemyType {
    Soldier, Kamikaze, Tank, Boss
};

class Enemy : public GameCharacter {
};


#endif //METALCFU_ENEMY_H
