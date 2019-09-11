//
// Created by emanuele on 11/09/19.
//

#include "DistanceAchieve.h"

DistanceAchieve::DistanceAchieve(Player *p, std::shared_ptr<sf::RenderWindow> rw) : AchievObserver(p, std::move(rw),
                                                                                                   "Do you like running?"),
                                                                                    distance(300) {
    startPosX = p->getPosition().x;
}

void DistanceAchieve::update() {
    if (abs(startPosX - subject->getPosition().x) >= distance) {
        doneAchieve = true;
    }
}
