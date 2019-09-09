//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_POWERBARREL_H
#define METALCFU_POWERBARREL_H

#include "Attachment.h"

class PowerBarrel : public Attachment {
public:
    explicit PowerBarrel(int id = 8) : Attachment{id} {
        auto powerBar = new sf::Texture();
        powerBar->loadFromFile(
                "Sources/Pngs/Attachments/power_barrel.png");
        this->setTexture(*powerBar);
    };

    ~PowerBarrel() final = default;

    void improve(Weapon &w);
};


#endif //METALCFU_POWERBARREL_H
