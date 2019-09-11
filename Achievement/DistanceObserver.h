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

    void attach() override;

    void detach() override;

    void update() override;

private:
    std::shared_ptr<Player> subject;
    float startPosX;
    float distance;
};


#endif //METALCFU_DISTANCEOBSERVER_H
