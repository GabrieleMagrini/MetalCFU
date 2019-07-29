//
// Created by madmag on 22/06/19.
//

#include "Terrain.h"
#include "Collision.h"


void Terrain::checkCollision(GameCharacter *g) {
    if (g->getSpeedX() >= 0)
        g->setCollisionX(((this->getPosition().x) - (g->getPosition().x + g->getTexture()->getSize().x)) <= 0);
    else if (g->getSpeedX() <= 0)
        g->setCollisionX(((this->getPosition().x + this->getTexture()->getSize().x) - g->getPosition().x) >= 0);
    if (g->getSpeedY() >= 0 && g->getPosition().x == this->getPosition().x)
        g->setCollisionY(((this->getPosition().y) - (g->getPosition().y + g->getTexture()->getSize().y)) <= 0);
    else if (g->getSpeedY() <= 0 && g->getPosition().x == this->getPosition().x)
        g->setCollisionY(((this->getPosition().y + this->getTexture()->getSize().y) - g->getPosition().y) >= 0);

}

int Terrain::setBonus(GameCharacter *g, int bonusSpeedMovement) {
    while ((g->getCollisionY()) && Collision::PixelPerfectTest(*g, *this))
        g->setSpeedX(g->getSpeedX() + bonusSpeedMovement);

}