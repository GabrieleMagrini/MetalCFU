//
// Created by madmag on 22/06/19.
//

#ifndef METALCFU_BARRIER_H
#define METALCFU_BARRIER_H


#include "Interactable.h"

class Barrier : public Interactable {
public:
    explicit Barrier() {
        auto barrier = new sf::Texture();
        barrier->loadFromFile("Sources/Pngs/Interactable textures/Barrier.png");
        this->setTexture(*barrier);
    }
     ~Barrier() override = default;
};


#endif //METALCFU_BARRIER_H
