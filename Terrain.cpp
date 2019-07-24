//
// Created by madmag on 22/06/19.
//

#include "Terrain.h"
#include "Collision.h"


void Terrain::checkCollision(GameCharacter *g, Ammo *a, Weapon *w, Interactable *i) {

    g->setCollisionX((g->getPosition().x + g->getTexture()->getSize().x) ==
                     ((this->getPosition().x) - (this->getTexture()->getSize().x)) ||
                     (g->getPosition().x - g->getTexture()->getSize().x) ==
                     ((this->getPosition().x) + (this->getTexture()->getSize().x)));
    g->setCollisionY((g->getPosition().y - g->getTexture()->getSize().y) ==
                     ((this->getPosition().y) + (this->getTexture()->getSize().y)));
    a->setCollision(Collision::PixelPerfectTest(*a, *this));
    w->setCollision(Collision::PixelPerfectTest(*w, *this));
    i->setCollision(Collision::PixelPerfectTest(*i, *this));
}

int Terrain::setBonus(GameCharacter *g, int bonusSpeedMovement) {
    while ((g->getCollisionX()) && Collision::PixelPerfectTest(*g, *this))
        g->setSpeedX(g->getSpeedX() + bonusSpeedMovement);

}