//
// Created by madmag on 22/06/19.
//

#include "Terrain.h"
#include "Collision.h"


void Terrain::checkCollision(GameCharacter *g, Ammo *a, Weapon *w, Interactable *i) {

    g->setCollision(Collision::PixelPerfectTest(*g, *this));
    a->setCollision(Collision::PixelPerfectTest(*a, *this));
    w->setCollision(Collision::PixelPerfectTest(*w, *this));
    i->setCollision(Collision::PixelPerfectTest(*i, *this));
}