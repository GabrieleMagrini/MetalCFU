//
// Created by madmag on 13/07/19.
//

#ifndef METALCFU_BEHAVIOUR_H
#define METALCFU_BEHAVIOUR_H


class Behaviour {
public:
    void action();
};

class patrolBehaviour : public Behaviour {
};

class attackBehaviour : public Behaviour {
};

class specialBehaviour : public Behaviour {
};

#endif //METALCFU_BEHAVIOUR_H
