//
// Created by emanuele on 11/09/19.
//

#ifndef METALCFU_BOOMOBSERVER_H
#define METALCFU_BOOMOBSERVER_H

#include "Observer.h"
#include "../Player.h"

class BoomObserver : public Observer {
public:
    explicit BoomObserver(Player *p);

    ~BoomObserver() final;

    void attach() override;

    void detach() override;

    void update() override;

private:
    Player *subject;
    int granadeCounter;
};


#endif //METALCFU_BOOMOBSERVER_H
