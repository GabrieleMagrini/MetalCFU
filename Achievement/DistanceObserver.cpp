//
// Created by emanuele on 10/09/19.
//

#include "DistanceObserver.h"


DistanceObserver::DistanceObserver(Player *p) : subject(p), distanceTraveled(0), distanceMax(300),
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
    startPosX = subject->getPosition().x;
    if (distanceTraveled >= distanceMax) {
        subject->unlock(AchievementType::DISTANCE);
        detach();
    }
}

DistanceObserver::~DistanceObserver() {
    detach();
    delete subject;
}