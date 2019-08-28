//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_MEDKIT_H
#define METALCFU_MEDKIT_H


#include "Usable.h"

class MedKit: public Usable {
public:
    explicit MedKit(int hp) : Usable(hp) {};
    ~MedKit() override = default;

    int use(GameCharacter &g) override;
};


#endif //METALCFU_MEDKIT_H
