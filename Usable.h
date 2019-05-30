//
// Created by emanuele on 27/05/19.
//

#ifndef METALCFU_USABLE_H
#define METALCFU_USABLE_H


class Usable {
public:
    Usable();

    virtual ~Usable() = default;
    virtual void use() = 0;
private:
    //da definire
};


#endif //METALCFU_USABLE_H
