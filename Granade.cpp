//
// Created by emanuele on 14/06/19.
//

#include "Granade.h"

/**
 * function that trhow the granade;
 * @param g
 * @return
 */
int Granade::use(GameCharacter &g) {
    //TODO trow granade
    if (!collision && explosionTime > 0)
        move(5, 0);
    return 0;
}

/**
 *
 * @param d damage of the granade
 * @param expTime explosion timer
 */
Granade::Granade(int d, int expTime) : Usable(d, "Sources/Pngs/weapon textures/sheetGranade.png"),
                                       explosionTime(expTime) {
    texture.loadFromFile(fileName);
    setTexture(texture);
    setTextureRect(sf::IntRect(0, 0, 26, 26));
}

int Granade::getExplosionTime() const {
    return explosionTime;
}

void Granade::setExplosionTime(int explosionTime) {
    Granade::explosionTime = explosionTime;
}

/**
 * function that check hit with enemies, if enemy was hitted then some damage will inflicted
 * @param e vector of enemy
 */
void Granade::checkHit(std::vector<Enemy> &e) {
    for (auto &en : e) {
        if (en.getGlobalBounds().intersects(getGlobalBounds())) {
            en.getDamage(data);
            if (en.getHp() < 0)
                en.setHp(0);
        }
    }
}
