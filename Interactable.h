//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_INTERACTABLE_H
#define METALCFU_INTERACTABLE_H

#include <SFML/Graphics.hpp>

class Interactable : public sf::Sprite {
public:
    explicit Interactable(bool c = false, int HP = 1000) : collision(c), hp(HP) {};

    ~Interactable() override = default;

    void setCollision(bool v);

    bool getCollision();

    int getHp() const;

    void setHp(int hp);

protected:

    bool collision;
    int hp;

};


#endif //METALCFU_INTERACTABLE_H
