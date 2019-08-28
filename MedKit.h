//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_MEDKIT_H
#define METALCFU_MEDKIT_H


#include "Usable.h"

class MedKit: public Usable {
public:
    explicit MedKit(int hp):healerPoints(hp){};
    ~MedKit() override = default;

    void setHealerPoints(int healerPoints);

    int use(GameCharacter &g) override;

private:
    int healerPoints;
};


#endif //METALCFU_MEDKIT_H
