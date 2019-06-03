//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_MEDKIT_H
#define METALCFU_MEDKIT_H


#include "Usable.h"

class MedKit: public Usable {
public:
    explicit MedKit(int h):healerPoints(h){};
    ~MedKit() override = default;


    void use(GameCharacter* g) override;

    int getHealerPoints() const;

    void setHealerPoints(int healerPoints);

private:
    int healerPoints;
};


#endif //METALCFU_MEDKIT_H
