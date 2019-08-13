//
// Created by madmag on 22/06/19.
//

#include <iostream>
#include "Terrain.h"


void Terrain::checkCollision(GameCharacter &g) {
    sf::FloatRect flDownPlayer = sf::Rect<float>(g.getPosition().x - g.getLocalBounds().width / 2,
                                                 g.getPosition().y + g.getLocalBounds().height,
                                                 g.getLocalBounds().width, 5); // rettangolo in basso al personaggio
    sf::FloatRect flUpPlayer = sf::Rect<float>(g.getPosition().x - g.getLocalBounds().width / 2, g.getPosition().y,
                                               this->getLocalBounds().width, 5); //rettangolo in alto al personaggio

    sf::FloatRect flRightPlayer = sf::Rect<float>(g.getPosition().x + g.getLocalBounds().width / 2 - 5,
                                                  g.getPosition().y,
                                                  5, g.getLocalBounds().height); // rettangolo a destra del personaggio
    sf::FloatRect flLeftPlayer = sf::Rect<float>(g.getPosition().x - g.getLocalBounds().width / 2, g.getPosition().y, 5,
                                                 this->getLocalBounds().height);   // rettangolo a sinistra del personaggio

    sf::FloatRect flUpBlock = sf::Rect<float>(this->getPosition().x, this->getPosition().y,
                                              this->getLocalBounds().width, 25); //rettangolo in alto al blocco
    sf::FloatRect flDownBlock = sf::Rect<float>(this->getPosition().x,
                                                this->getPosition().y + this->getLocalBounds().height - 25,
                                                this->getLocalBounds().width, 25); //rettangolo in basso al blocco
    sf::FloatRect flLeftBlock = sf::Rect<float>(this->getPosition().x, this->getPosition().y + 25, 25,
                                                this->getLocalBounds().height - 50); //rettangolo a sinistra del blocco
    sf::FloatRect flRightBlock = sf::Rect<float>(this->getPosition().x + this->getLocalBounds().width - 25,
                                                 this->getPosition().y + 25, 25, this->getLocalBounds().height - 50);
    //rettangolo a destra del blocco

    if (flUpBlock.intersects(flDownPlayer)) {
        g.setCollisionDown(true);
    }

    if (flDownBlock.intersects(flUpPlayer)) {
        g.setCollisionUp(true);
    }
    if (flLeftBlock.intersects(flRightPlayer)) {
        g.setCollisionRight(true);
    }
    if (flRightBlock.intersects(flLeftPlayer)) {
        g.setCollisionLeft(true);
    }


}
/*
int Terrain::setBonus(GameCharacter &g) {
    while ((g.isCollisionDown()) && Collision::PixelPerfectTest(g, *this))
        g.setSpeedX(g.getSpeedX() + bonusSpeedMovement);

    return 0;
}
 */