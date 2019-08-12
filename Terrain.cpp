//
// Created by madmag on 22/06/19.
//

#include <iostream>
#include "Terrain.h"
#include "Collision.h"


void Terrain::checkCollision(GameCharacter &g) {
    /* if (g->getSpeedX() >= 0)
         g->setCollisionX(((this->getPosition().x) - (g->getPosition().x + g->getTexture()->getSize().x)) <= 0);
     else if (g->getSpeedX() <= 0)
         g->setCollisionX(((this->getPosition().x + this->getTexture() ->getSize().x) - g->getPosition().x) >= 0);
     if (g->getSpeedY() >= 0 && g->getPosition().x == this->getPosition().x)
         g->setCollisionY(((this->getPosition().y) - (g->getPosition().y + g->getTexture()->getSize().y)) <= 0);
     else if (g->getSpeedY() <= 0 && g->getPosition().x == this->getPosition().x)
         g->setCollisionY(((this->getPosition().y + this->getTexture()->getSize().y) - g->getPosition().y) >= 0);
 */
    sf::FloatRect flDownPlayer = sf::Rect<float>(g.getPosition().x - g.getLocalBounds().width / 2,
                                                 g.getPosition().y + g.getLocalBounds().height,
                                                 g.getLocalBounds().width, 5); // rettangolo in basso al giocatore
    sf::FloatRect flUpPlayer = sf::Rect<float>(g.getPosition().x - g.getLocalBounds().width / 2, g.getPosition().y,
                                               this->getLocalBounds().width, 5);

    sf::FloatRect flUpBlock = sf::Rect<float>(this->getPosition().x, this->getPosition().y,
                                              this->getLocalBounds().width, 25);
    sf::FloatRect flDownBlock = sf::Rect<float>(this->getPosition().x,
                                                this->getPosition().y + this->getLocalBounds().height - 25,
                                                this->getLocalBounds().width, 25);
    if (flUpBlock.intersects(flDownPlayer)) {
        g.setCollisionDown(true);
    }

    if (flDownBlock.intersects(flUpPlayer)) {
        g.setCollisionUp(true);
    }

}

int Terrain::setBonus(GameCharacter *g, int bonusSpeedMovement) {
    while ((g->getCollisionDown()) && Collision::PixelPerfectTest(*g, *this))
        g->setSpeedX(g->getSpeedX() + bonusSpeedMovement);

    return 0;
}