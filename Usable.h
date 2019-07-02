//
// Created by emanuele on 27/05/19.
//

#ifndef METALCFU_USABLE_H
#define METALCFU_USABLE_H

#include <SFML/Graphics.hpp>


class Usable: public sf::Sprite {
public:
    virtual int use()=0;
    ~Usable() override = default;
private:
    //da definire
};


#endif //METALCFU_USABLE_H
