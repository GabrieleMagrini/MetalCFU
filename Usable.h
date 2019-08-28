//
// Created by emanuele on 27/05/19.
//

#ifndef METALCFU_USABLE_H
#define METALCFU_USABLE_H

#include <SFML/Graphics.hpp>
#include "GameCharacter.h"

Class GameCharacter;

class Usable: public sf::Sprite {
public:
    virtual int use(GameCharacter &g) = 0;
    ~Usable() override = default;
private:
    bool collision;
};


#endif //METALCFU_USABLE_H
