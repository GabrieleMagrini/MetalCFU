//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_AMMO_H
#define METALCFU_AMMO_H

#include <SFML/Graphics.hpp>

class Ammo : public sf::Sprite {
public:

    explicit Ammo(int q = 100, bool c = false) : quantity(q), collision(c) {
        auto ammo = new sf::Texture();
        ammo->loadFromFile(
                "Sources/Pngs/player textures/dx/1.png");
        this->setTexture(*ammo);
    };

    Ammo(const Ammo &a) = default;

    bool operator==(const Ammo &a2) const;

    virtual ~Ammo() = default;

    int getQuantity() const;

    void setQuantity(int quantity);

    void setCollision(bool v);

    bool getCollision() const;


private:
    int quantity;
    bool collision;
};


#endif //METALCFU_AMMO_H
