//
// Created by emanuele on 27/06/19.
//

#include "EnemyFactory.h"
#include "WeaponFactory.h"


std::unique_ptr<Enemy> EnemyFactory::createEnemy(EnemyType et) {
    unique_ptr<Enemy> result;
    WeaponFactory wf;

    switch (et) {
        case EnemyType::Soldier:
            result = unique_ptr<Enemy>(
                    new Enemy{100, 0, 0, 10, nullptr, (wf.createWeapon(WeaponType::AK_47)).get(), nullptr,
                              "Sources/Pngs/Enemies/soldier.png", 1, 0, 4});
            break;
        case EnemyType::Tank:
            result = unique_ptr<Enemy>(
                    new Enemy{200, 0, 0, 10, nullptr, (wf.createWeapon(WeaponType::M4)).get(), nullptr,
                              "Sources/Pngs/Enemies/tank.png", 1, 0, 2});
            break;
        case EnemyType::Kamikaze:
            result = unique_ptr<Enemy>(
                    new Enemy{75, 0, 0, 20, nullptr, nullptr, nullptr, "Sources/Pngs/Enemies/kamikaze.png",
                              1, 0, 6});
            break;
        case EnemyType::Boss:
            result = unique_ptr<Enemy>(
                    new Enemy{500, 0, 0, 10, nullptr, (wf.createWeapon(WeaponType::AK_47)).get(), nullptr,
                              "Sources/Pngs/player textures/dx/1.png", 0, 0, 3});
    }
    return result;

}
