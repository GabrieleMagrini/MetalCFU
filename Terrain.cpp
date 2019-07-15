//
// Created by madmag on 22/06/19.
//

#include "Terrain.h"


int Terrain::checkCollision(GameCharacter *g, Ammo *a, Weapon *w, Interactable *i) {
    if (g->getLocalBounds().intersects(this->getLocalBounds()))
        g->setCollision(true);
    if (a->getLocalBounds().intersects(this->getLocalBounds()))
        a->setCollision(true);
    if (w->getLocalBounds().intersects(this->getLocalBounds()))
        w->setCollision(true);
    if (i->getLocalBounds().intersects(this->getLocalBounds()))
        i->setCollision(true);
}