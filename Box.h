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
    explicit Box(T t, int hp = 100);

    ~Box() override = default;

    unique_ptr<T> dropGift();

    void setGift(const unique_ptr<T> &gift);

    int getHp() const;

    void setHp(int hp);

private:
    unique_ptr<T> gift;
    int hp;
};

template<typename T>
Box<T>::Box(T t, int hp): gift(t), hp(hp) {

}

template<typename T>
unique_ptr<T> Box<T>::dropGift() {
    if (hp <= 0)
        return gift;
    else
        return nullptr;
}

template<typename T>
void Box<T>::setGift(const unique_ptr<T> &gift) {
    Box::gift = gift;
}

template<typename T>
int Box<T>::getHp() const {
    return hp;
}

template<typename T>
void Box<T>::setHp(int hp) {
    Box::hp = hp;
    if (this->hp < 0)
        this->hp = 0;
}


#endif //METALCFU_BOX_H
