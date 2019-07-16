//
// Created by madmag on 22/06/19.
//

#include "Terrain.h"


int Terrain::checkCollision(GameCharacter *g, Ammo *a, Weapon *w, Interactable *i) {

    g->setCollision(true);

    g->setCollision(false);
    if (a->getLocalBounds().intersects(this->getLocalBounds()))
        a->setCollision(true);
    else
        a->setCollision(false);
    if (w->getLocalBounds().intersects(this->getLocalBounds()))
        w->setCollision(true);
    else
        w->setCollision(false);
    if (i->getLocalBounds().intersects(this->getLocalBounds()))
        i->setCollision(true);
    else
        i->setCollision(false);
}