//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_LASERSCOPE_H
#define METALCFU_LASERSCOPE_H

#include "Attachment.h"

class LaserScope : Attachment {
public:

    LaserScope() {
        auto laser = new sf::Texture();
        laser->loadFromFile(
                "Sources/Pngs/Attachments/laser.png");
        this->setTexture(*laser);
    };

    ~LaserScope() final = default;

    void improve(Weapon &w) override;
};


#endif //METALCFU_LASERSCOPE_H
