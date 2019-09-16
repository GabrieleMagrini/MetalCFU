//
// Created by emanuele on 27/05/19.
//

#ifndef METALCFU_USABLE_H
#define METALCFU_USABLE_H

#include <SFML/Graphics.hpp>
#include <memory>

#include "GameCharacter.h"

class GameCharacter;

class Usable: public sf::Sprite {
public:
    Usable(int d, std::string fName) : data(d), collision(false), fileName(std::move(fName)),
                                       texture(std::make_shared<sf::Texture>(sf::Texture{})) {

        texture->loadFromFile(fileName);
        setTexture(*texture);
    };

    virtual void use(GameCharacter &g) = 0;
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
    std::string fileName;
    std::shared_ptr<sf::Texture> texture;
    int data;
    bool collision;
};


#endif //METALCFU_USABLE_H
