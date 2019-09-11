//
// Created by emanuele on 10/09/19.
//

#include "DistanceObserver.h"


DistanceObserver::DistanceObserver(Player *p) : subject(p), distanceTraveled(0), distanceMax(5000),
                                                startPosX(p->getPosition().x) {
    attach();
}

void DistanceObserver::attach() {
    subject->subscribe(this);
}

void DistanceObserver::detach() {
    subject->unsubscribe(this);
}

void DistanceObserver::update() {
    distanceTraveled = distanceTraveled + abs(subject->getPosition().x - startPosX);
    if (distanceTraveled >= distanceMax) {
        subject->unlock(AchievementType::DISTANCE);
        detach();
    }
}
