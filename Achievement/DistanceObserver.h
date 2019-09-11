//
// Created by emanuele on 10/09/19.
//

#ifndef METALCFU_DISTANCEOBSERVER_H
#define METALCFU_DISTANCEOBSERVER_H

#include "SFML/Graphics.hpp"

#include "Observer.h"
#include "../Player.h"

class player;

class DistanceObserver : public Observer {
public:
    explicit DistanceObserver(Player *p);

    ~DistanceObserver() final;

    void attach() override;

    void detach() override;

    void update() override;

private:
    Player *subject;
    float startPosX;
    float distanceTraveled;
    float distanceMax;
};


#endif //METALCFU_DISTANCEOBSERVER_H
