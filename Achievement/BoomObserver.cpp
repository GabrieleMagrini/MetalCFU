//
// Created by emanuele on 11/09/19.
//

#include "BoomObserver.h"

BoomObserver::BoomObserver(Player *p) : subject(p), granadeCounter(1) {
    attach();
}

BoomObserver::~BoomObserver() {
    detach();
    delete subject;
}

void BoomObserver::attach() {
    subject->subscribe(this);
}

void BoomObserver::detach() {
    subject->unsubscribe(this);
}

void BoomObserver::update() {
    if (subject->getGranadeCounter() >= granadeCounter) {
        subject->unlock(AchievementType::BOOM);
        detach();
    }
}
