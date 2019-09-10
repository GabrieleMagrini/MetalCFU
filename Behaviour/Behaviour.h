//
// Created by madmag on 13/07/19.
//

#ifndef METALCFU_BEHAVIOUR_H
#define METALCFU_BEHAVIOUR_H


#include "../Player.h"

class Enemy;

class Behaviour {
public:
    explicit Behaviour(const std::string &name) : name(name) {}

    virtual ~Behaviour() = default;

    virtual int action(Player &p, Enemy &e, Ammo &a) = 0;

    virtual std::string getName() { return name; };
private:
    std::string name;
};


#endif //METALCFU_BEHAVIOUR_H
