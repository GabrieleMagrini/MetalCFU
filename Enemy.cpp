//
// Created by emanuele on 26/06/19.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int x, int y, int s, Behaviour *b, Weapon *w, Usable *p, int mw, int mu, int sx, int sy, int sw,
             int su,
             int steps)
        : GameCharacter(
        hp, x, y, s, w, p, mw, mu, sx, sy, sw, su), startPosX(x), startposY(y), steps(steps), behaviour(b) {

}

/****
 * function that make do a patrol to the enemy
 */
/*void Enemy::Action(Behaviour *b) {
    b->action();

}*/
