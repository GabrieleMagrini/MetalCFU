//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_LONGBARREL_H
#define METALCFU_LONGBARREL_H

#include "Attachment.h"

class LongBarrel: public Attachment{
public:
    explicit LongBarrel(int r = 15) : Attachment{r} {
        auto longBar = new sf::Texture();
        longBar->loadFromFile(
                "Sources/Pngs/Attachments/longBarrel.png");
        this->setTexture(*longBar);
    };

      ~LongBarrel() final = default;

    void improve(Weapon &w);
};


#endif //METALCFU_LONGBARREL_H
