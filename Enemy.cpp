//
// Created by emanuele on 26/06/19.
//

#include "Enemy.h"
#include "Player.h"
#include "Behaviour/attackBehaviour.h"
#include "Behaviour/patrolBehaviour.h"

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
void Enemy::Action(Player *p) {
    Enemy::behaviour->action(p);

}

Behaviour *Enemy::getBehaviour() const {
    return behaviour;
}

void Enemy::setBehaviour(Behaviour *behaviour) {
    Enemy::behaviour = behaviour;
}

void Enemy::checkBehaviour(Player *p) {
    auto attack = new attackBehaviour();
    auto patrol = new patrolBehaviour();
    auto Y = p->getPosY();
    auto X = p->getPosX();
    if ((abs(getPosY() - Y)) < 3 && (abs(getPosX() - X)) < 7)
        setBehaviour(attack);
    else
        setBehaviour(patrol);

}