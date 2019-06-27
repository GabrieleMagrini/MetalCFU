//
// Created by emanuele on 27/06/19.
//

#ifndef METALCFU_ENEMYFACTORY_H
#define METALCFU_ENEMYFACTORY_H

#include <memory>

#include "../Enemy.h"

enum class EnemyType{Soldier,Tank,Kamikaze,Boss};

class EnemyFactory {
public:

    virtual ~EnemyFactory() = default;

    std::unique_ptr<Enemy> createEnemy(EnemyType et);
};


#endif //METALCFU_ENEMYFACTORY_H
