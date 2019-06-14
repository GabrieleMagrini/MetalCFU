//
// Created by emanuele on 14/06/19.
//

#ifndef METALCFU_GRANADE_H
#define METALCFU_GRANADE_H


#include "Usable.h"

class Granade: public Usable {
public:
    explicit Granade(int d):damage(d){};

    ~Granade() override = default;

    int getDamage() const;

    void setDamage(int damage);

    int use() override;
private:
    int damage;
};


#endif //METALCFU_GRANADE_H
