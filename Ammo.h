//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_AMMO_H
#define METALCFU_AMMO_H

#include <SFML/Graphics.hpp>

class Ammo : public sf::Sprite {
public:

    explicit Ammo(int q = 100, bool c = false, bool s = false) : quantity(q), collision(c), isShot(s) {
        auto ammo = new sf::Texture();
        ammo->loadFromFile(
                "Sources/Pngs/weapon textures/ammo.png");
        this->setTexture(*ammo);
    };

    Ammo(const Ammo &a) = default;

    bool operator==(const Ammo &a2) const;

    virtual ~Ammo() = default;

    int getQuantity() const;

    void setQuantity(int quantity);

    void setCollision(bool v);

    bool getCollision() const;

    void shoot(sf::Vector2f posRif, sf::Vector2f posFin);

    bool isIsShot() const;

    void setIsShot(bool isShot);

private:
    int quantity;
    bool collision;
    bool isShot;
};


#endif //METALCFU_AMMO_H
