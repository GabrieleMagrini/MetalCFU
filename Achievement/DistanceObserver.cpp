//
// Created by emanuele on 10/09/19.
//

#include "DistanceObserver.h"


DistanceObserver::DistanceObserver(Player *p) : subject(p), distance(1000), startPosX(p->getPosition().x) {
    attach();
}

void DistanceObserver::attach() {
    subject->subscribe(this);
}

void DistanceObserver::detach() {
    subject->unsubscribe(this);
}

void DistanceObserver::update() {
    if (abs(subject->getPosition().x - startPosX) >= distance) {

    }
}
