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
                                       explosionTime(expTime), trow(false) {
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
    if (explosionTime == 0)
        for (auto &en : e) {
            if (en.getGlobalBounds().intersects(getGlobalBounds())) {
                en.getDamage(data);
                if (en.getHp() < 0)
                    en.setHp(0);
            }
        }
}

bool Granade::isTrow() const {
    return trow;
}

void Granade::setTrow(bool trow) {
    Granade::trow = trow;
}

/***
 * texture rect update when explosion of the granade
 * @param idx index of the texture in the file
 */
void Granade::setTextureExpl(int idx) {
    sf::IntRect ir = sf::IntRect(121 * idx, 27, 120, 118);
    setTextureRect(ir);
}
