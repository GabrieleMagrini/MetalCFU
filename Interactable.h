//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_INTERACTABLE_H
#define METALCFU_INTERACTABLE_H

#include <SFML/Graphics.hpp>

class Interactable : public sf::Sprite {
public:
    explicit Interactable(bool c = false) : collision(c) {};

    ~Interactable() override = default;

    void setCollision(bool v);

    bool getCollision();

    int getSpeedY() const;

    void setSpeedY(int speedY);

private:

    bool collision;

};


#endif //METALCFU_INTERACTABLE_H
