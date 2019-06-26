//
// Created by emanuele on 26/06/19.
//

#ifndef METALCFU_BOX_H
#define METALCFU_BOX_H

#include <memory>

#include "Interactable.h"

using namespace std;

template<typename T>
class Box : public Interactable {
public:
    explicit Box(T t, int hp=100);

    ~Box() override = default;
    T dropGift();
private:
    unique_ptr<T> gift;
    int hp;
};

template<typename T>
Box<T>::Box(T t, int hp): gift(t), hp(hp) {

}

template<typename T>
T Box<T>::dropGift() {
    if(hp<=0)
        return gift;
    else
        return nullptr;
}


#endif //METALCFU_BOX_H
