//
// Created by emanuele on 27/06/19.
//

#include "EnemyFactory.h"
#include "WeaponFactory.h"
#include "../SpecialAttack/Charge.h"
#include "../SpecialAttack/Kamikaze.h"
#include "../SpecialAttack/BossAttack.h"

std::unique_ptr<Enemy> EnemyFactory::createEnemy(EnemyType et) {
    unique_ptr<Enemy> result;
     WeaponFactory wf;
     switch(et){
         case EnemyType::Soldier:
             result = unique_ptr<Enemy>(
                     new Enemy(100, 0, 0, 10, nullptr, (wf.createWeapon(WeaponType::M4)).get(), nullptr));
             break;
         case EnemyType::Tank:
             result = unique_ptr<Enemy>(
                     new Enemy(200, 0, 0, 10, nullptr, (wf.createWeapon(WeaponType::M4)).get(), nullptr, 0, 0, 5));
             break;
         case EnemyType ::Kamikaze:
             result = unique_ptr<Enemy>(new Enemy(75, 0, 0, 40, nullptr, nullptr, nullptr, 0, 0, 15));
             break;
         case EnemyType ::Boss:
             result = unique_ptr<Enemy>(
                     new Enemy(500, 0, 0, 10, nullptr, (wf.createWeapon(WeaponType::AK_47)).get(), nullptr, 0, 0, 10));
     }
    return result;

}
