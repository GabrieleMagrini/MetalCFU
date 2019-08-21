//
// Created by madmag on 21/07/19.
//

#include "attackBehaviour.h"


int attackBehaviour::action(Player *p, Enemy *e) {
    auto bullet = new Ammo;
    if (e->getWeapon()->getCurrentAmmo())
        bullet->setPosition(e->getWeapon()->getPosition());
    bullet->setIsShot(e->getWeapon()->shoot());
    if (e->getPosition().x - p->getPosition().x > 0)
        e->setPosition(e->getPosition().x - 1, e->getPosition().y);
    if (e->getPosition().y - p->getPosition().y < 0)
        e->setPosition(e->getPosition().x + 1, e->getPosition().y);
    if (e->isCollisionLeft() || e->isCollisionRight())
        e->jump(100, e->getPosition().y);
    return 0;
}
