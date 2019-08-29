//
// Created by emanuele on 14/06/19.
//

#ifndef METALCFU_GRANADE_H
#define METALCFU_GRANADE_H


#include "Usable.h"
#include "Enemy.h"

class Enemy;

class Granade: public Usable {
public:
    explicit Granade(int d, int expTime);

    ~Granade() final = default;

    int use(GameCharacter &g) override;

    int getExplosionTime() const;

    void setExplosionTime(int explosionTime);

    void checkHit(std::vector<Enemy> &e);

private:
    int explosionTime;

};


#endif //METALCFU_GRANADE_H
