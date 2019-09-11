//
// Created by emanuele on 10/09/19.
//

#include "AchievObserver.h"


AchievObserver::AchievObserver(Player *p) : subject(p) {
    attach();
}

void AchievObserver::attach() {
    subject->subscribe(this);
}

void AchievObserver::detach() {
    subject->unsubscribe(this);
}

void AchievObserver::update() {

}
