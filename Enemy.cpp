//
// Created by emanuele on 26/06/19.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int x, int y, int s, Behaviour *b, Weapon *w, Usable *p, int mw, int mu, int sx, int sy, int sw,
             int su,
             int steps, bool presence)
        : GameCharacter(
        hp, x, y, s, w, p, mw, mu, sx, sy, sw, su), startPosX(x), startposY(y), steps(steps), behaviour(b),
          playerPresence(presence) {

}

/****
 * function that make do a patrol to the enemy
 */
void Enemy::Action() {
    Enemy::behaviour->action();

}

Behaviour *Enemy::getBehaviour() const {
    return behaviour;
}

void Enemy::setBehaviour(Behaviour *behaviour) {
    Enemy::behaviour = behaviour;
}
