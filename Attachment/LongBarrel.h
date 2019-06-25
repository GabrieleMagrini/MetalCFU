//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_LONGBARREL_H
#define METALCFU_LONGBARREL_H

#include "../Attachment.h"

class LongBarrel: public Attachment{
public:
    explicit LongBarrel(int r = 15) : range(r) {};

      ~LongBarrel() final = default;

    void Improve(Weapon &w) override;


private:
    int range;
};


#endif //METALCFU_LONGBARREL_H
