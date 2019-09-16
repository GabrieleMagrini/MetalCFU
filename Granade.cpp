//
// Created by emanuele on 14/06/19.
//

#include "Granade.h"

/**
 * function that trhow the granade;
 * @param g
 * @return
 */
void Granade::use(GameCharacter &g) {

    if (!collision && explosionTime > 0) {
        if (direction == 1)
            move(7, 0);
        if (direction == 0)
            move(-7, 0);
    }
}

/**
 *
 * @param d damage of the granade
 * @param expTime explosion timer
 */
Granade::Granade(int d, int expTime) : Usable(d, "Sources/Pngs/weapon textures/sheetGranade.png"),
                                       explosionTime(expTime), trow(false), direction(1) {
    texture->loadFromFile(fileName);
    setTexture(*texture);
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
    if (idx == 0)
        setPosition(getPosition().x - getTextureRect().width / 2.0f + 26,
                    getPosition().y - getTextureRect().height / 2.0f);

}

/**
 * setting the direction of the throw of the granade 1 right, 0 left
 * @param d the direction of the throw
 */
void Granade::setDirection(int d) {
    if (d != 0 && d != 1)
        d = 1;
    this->direction = d;
}

/***
 *
 * @return the direction of the throw of the granade
 */
int Granade::getDirection() const {
    return direction;
}

Granade::Granade(Granade &g) : Usable(g.data, g.fileName) {
    explosionTime = g.explosionTime;
    trow = g.trow;
    direction = g.direction;
}
