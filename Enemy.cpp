//
// Created by emanuele on 26/06/19.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw, int mu, int ms, int sw, int su, int steps,
             SpecialAttack *sa)
        : GameCharacter(
        hp, x, y, s, w, p, mw, mu, ms, sw, su), startPosX(x), startposY(y), steps(steps), specAttack(sa) {

}

/****
 * function that make do a patrol to the enemy
 */
void Enemy::Behaviour() {
    if (posX > startPosX)
        if (abs(posX - startPosX) < steps)
            posX += movementSpeed;
        else
            posX -= movementSpeed;
    else if (abs(posX - startPosX) < steps)
        posX--;
    else
        posX -= movementSpeed;

}

void Enemy::doSpecial() {
    if(specAttack!= nullptr){
        specAttack->doSpecial();
    }
}
