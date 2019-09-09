//
// Created by emanuele on 14/06/19.
//

#ifndef METALCFU_ATTACHMENT_H
#define METALCFU_ATTACHMENT_H


#include "../Weapon.h"

class Attachment : public Sprite {
public:
    explicit Attachment(int imp=0):improvement(imp) {};

    virtual ~Attachment()= default;

    int getImprovement() const {
        return improvement;
    }

    void setImprovement(int improvement) {
        Attachment::improvement = improvement;
    }

protected:
    int improvement;
};


#endif //METALCFU_ATTACHMENT_H
