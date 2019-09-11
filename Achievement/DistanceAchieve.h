//
// Created by emanuele on 11/09/19.
//

#ifndef METALCFU_DISTANCEACHIEVE_H
#define METALCFU_DISTANCEACHIEVE_H

#include "AchievObserver.h"

class DistanceAchieve : public AchievObserver {
public:
    DistanceAchieve(Player *p, std::shared_ptr<sf::RenderWindow> rw);

    void update() override;


private:
    int startPosX;
    int distance;
};


#endif //METALCFU_DISTANCEACHIEVE_H
