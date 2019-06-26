//
// Created by emanuele on 26/06/19.
//

#include "Enemy.h"

Enemy::Enemy(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw, int mu, int ms, int sw, int su) : GameCharacter(
        hp, x, y, s, w, p, mw, mu, ms, sw, su), startPosX(x), startposY(y) {

}