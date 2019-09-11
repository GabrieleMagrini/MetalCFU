//
// Created by emanuele on 11/09/19.
//

#include "KillObserver.h"

KillObserver::KillObserver(Player *p) : subject(p), nKill(3) {
    attach();
}

void KillObserver::attach() {
    subject->subscribe(this);
}

void KillObserver::detach() {
    subject->unsubscribe(this);
}

void KillObserver::update() {
    if (subject->getNKill() >= nKill) {
        subject->unlock(AchievementType::KILL);
        detach();
    }
}
