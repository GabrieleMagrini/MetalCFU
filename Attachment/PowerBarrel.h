//
// Created by emanuele on 25/06/19.
//

#ifndef METALCFU_POWERBARREL_H
#define METALCFU_POWERBARREL_H

#include "../Attachment.h"

class PowerBarrel: public Attachment {
public:
    explicit PowerBarrel(int id=3): improveDamage(id) {};
    ~PowerBarrel() final = default;

    void improve(Weapon &w) override;
private:
    int improveDamage;
};


#endif //METALCFU_POWERBARREL_H
