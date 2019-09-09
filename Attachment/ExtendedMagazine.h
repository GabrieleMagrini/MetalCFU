//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_EXTENDEDMAGAZINE_H
#define METALCFU_EXTENDEDMAGAZINE_H

#include "Attachment.h"

class ExtendedMagazine:public Attachment {
public:
    explicit ExtendedMagazine(int q = 30) : Attachment{q} {
        auto magazine = new sf::Texture();
        magazine->loadFromFile(
                "Sources/Pngs/Attachments/extMag.png");
        this->setTexture(*magazine);

    };
    ~ExtendedMagazine() final = default;

    void improve(Weapon &w) override;
};


#endif //METALCFU_EXTENDEDMAGAZINE_H
