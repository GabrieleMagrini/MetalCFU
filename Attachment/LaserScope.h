//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_LASERSCOPE_H
#define METALCFU_LASERSCOPE_H

#include "../Attachment.h"
class LaserScope: Attachment {
    LaserScope();
    ~LaserScope() final = default;

    void improve(Weapon &w) override;
};


#endif //METALCFU_LASERSCOPE_H
