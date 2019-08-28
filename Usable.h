//
// Created by emanuele on 27/05/19.
//

#ifndef METALCFU_USABLE_H
#define METALCFU_USABLE_H

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"

class GameCharacter;

class Usable: public sf::Sprite {
public:
    explicit Usable(int d) : data(d), collision(false) {};
    virtual int use(GameCharacter &g) = 0;
    ~Usable() override = default;

    int getData() const {
        return data;
    }

    void setData(int data) {
        Usable::data = data;
    }

    bool isCollision() const {
        return collision;
    }

    void setCollision(bool collision) {
        Usable::collision = collision;
    }

protected:

    int data;
    bool collision;
};


#endif //METALCFU_USABLE_H
