//
// Created by emanuele on 14/06/19.
//

#ifndef METALCFU_ATTACHMENT_H
#define METALCFU_ATTACHMENT_H


#include "Weapon.h"

class Attachment {
public:
    virtual void Improve(Weapon* w)=0;
    virtual ~Attachment()= default;
};


#endif //METALCFU_ATTACHMENT_H
