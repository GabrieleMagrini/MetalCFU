//
// Created by emanuele on 26/06/19.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int x, int y, int s, Weapon *w, Usable *p, SpecialAttack *sa, int mw, int mu, int ms, int sw,
             int su,
             int steps)
        : GameCharacter(
        hp, x, y, s, w, p, mw, mu, ms, sw, su), startPosX(x), startposY(y), steps(steps), specAttack(sa) {

}

/****
 * function that make do a patrol to the enemy
 */
void Enemy::Behaviour() {
    if (getPosX() > startPosX)
        if (abs(getPosY() - startPosX) < steps)
            setPosition(getPosX(),getPosY()+movementSpeed);
        else
            setPosition(getPosX()-movementSpeed,getPosY());
    else if (abs(getPosX() - startPosX) < steps)
        setPosition(getPosX()-1,getPosY());
    else
        setPosition(getPosX()-movementSpeed,getPosY());

}

void Enemy::doSpecial() {
    if(specAttack!= nullptr){
        specAttack->doSpecial();
    }
}
