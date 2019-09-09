//
// Created by emanuele on 14/06/19.
//

#ifndef METALCFU_ATTACHMENT_H
#define METALCFU_ATTACHMENT_H


#include "../Weapon.h"

class Weapon;

class Attachment : public Sprite {
public:
    explicit Attachment(int imp=0):improvement(imp) {};

    virtual ~Attachment() override = default;

    int getImprovement() const {
        return improvement;
    }

    void setImprovement(int improvement) {
        Attachment::improvement = improvement;
    }

    virtual void improve(Weapon &w) = 0;

protected:
    int improvement;
};


#endif //METALCFU_ATTACHMENT_H
