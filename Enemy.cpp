//
// Created by emanuele on 26/06/19.
//

#include "Enemy.h"
#include "Player.h"
#include "Behaviour/attackBehaviour.h"
#include "Behaviour/patrolBehaviour.h"
#include "Behaviour/suicidalBehaviour.h"

Enemy::Enemy(int hp, int x, int y, int s, Behaviour *b, Weapon *w, Usable *p, const string &filename, int mw, int mu,
             int sx, int sy, int sw,
             int su, int steps, bool presence)
        : GameCharacter(hp, x, y, s, w, p, mw, mu, sx, sy, sw, su, false, filename), startPosX(x), startposY(y),
          steps(steps), behaviour(b), playerPresence(presence) {

}

/****
 * function that make do a patrol to the enemy
 */
void Enemy::Action(Player *p, Enemy *e, Ammo &a) {
    Enemy::behaviour->action(p, this, a);

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
    auto suicidal = new suicidalBehaviour();
    if ((abs(getPosX() - p->getPosX())) < 250) {
        setBehaviour(attack);
    } else {
        if (this->getHp() < 10)
            setBehaviour(suicidal);
        else
            setBehaviour(patrol);
    }
}

Enemy::~Enemy() {
    delete behaviour;
}