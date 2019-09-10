
// Created by emanuele on 10/09/19.
//

#ifndef METALCFU_OBSERVER_H
#define METALCFU_OBSERVER_H

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update() = 0;

    virtual void attach() = 0;

    virtual void detach() = 0;

};


#endif //METALCFU_OBSERVER_H
