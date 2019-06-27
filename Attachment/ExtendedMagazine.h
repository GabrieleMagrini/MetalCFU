//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_EXTENDEDMAGAZINE_H
#define METALCFU_EXTENDEDMAGAZINE_H

#include "Attachment.h"

class ExtendedMagazine:public Attachment {
public:
    explicit ExtendedMagazine(int q=30):Attachment{q} {};
    ~ExtendedMagazine() final = default;

    void improve(Weapon &w) override;
};


#endif //METALCFU_EXTENDEDMAGAZINE_H
