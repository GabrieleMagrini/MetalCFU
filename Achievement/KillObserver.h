//
// Created by emanuele on 11/09/19.
//

#ifndef METALCFU_KILLOBSERVER_H
#define METALCFU_KILLOBSERVER_H

#include "Observer.h"
#include "../Player.h"

class KillObserver : public Observer {
public:
    explicit KillObserver(Player *p);

    ~KillObserver() final;

    void attach() override;

    void detach() override;

    void update() override;

private:
    Player *subject;
    int nKill;
};


#endif //METALCFU_KILLOBSERVER_H
