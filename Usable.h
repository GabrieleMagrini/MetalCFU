//
// Created by emanuele on 27/05/19.
//

#ifndef METALCFU_USABLE_H
#define METALCFU_USABLE_H


class Usable {
public:
    Usable();

    virtual ~Usable() = default;
    void use();
private:
    int size;
    int maxObj;// da definire
    int currObj;
};


#endif //METALCFU_USABLE_H
