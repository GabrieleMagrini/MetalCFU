//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_MEDKIT_H
#define METALCFU_MEDKIT_H


#include "Usable.h"

class MedKit: public Usable {
public:
    MedKit() : Usable(45, "Sources/Pngs/weapon textures/medikit.png") {
        texture->loadFromFile(fileName);
        setTexture(*texture);
    };
    ~MedKit() override = default;

    void use(GameCharacter &g) override;
};


#endif //METALCFU_MEDKIT_H
