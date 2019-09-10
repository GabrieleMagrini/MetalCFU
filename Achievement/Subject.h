//
// Created by emanuele on 10/09/19.
//

#ifndef METALCFU_SUBJECT_H
#define METALCFU_SUBJECT_H

#include "Observer.h"

class Subject {
public:
    virtual ~Subject() = default;

    virtual void subscribe(Observer *ac) = 0;

    virtual void unsubscribe(Observer *ac) = 0;

    virtual void notify() = 0;
};


#endif //METALCFU_SUBJECT_H
