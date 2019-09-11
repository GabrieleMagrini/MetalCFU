//
// Created by emanuele on 10/09/19.
//

#ifndef METALCFU_ACHIEVOBSERVER_H
#define METALCFU_ACHIEVOBSERVER_H

#include "SFML/Graphics.hpp"

#include "Observer.h"
#include "../Player.h"

class player;

class AchievObserver : public Observer {
public:
    explicit AchievObserver(Player *p);

    void attach() override;

    void detach() override;

    void update() override;

private:
    std::shared_ptr<Player> subject;
};


#endif //METALCFU_ACHIEVOBSERVER_H
