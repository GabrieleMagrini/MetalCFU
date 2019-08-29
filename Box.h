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
    explicit Box(T t);

    ~Box() override = default;

    unique_ptr<T> dropGift();

    void setGift(const unique_ptr<T> &gift);

private:
    T gift;

};

template<typename T>
Box<T>::Box(T t): gift(t) {
    auto box = new sf::Texture();
    box->loadFromFile(
            "Sources/Pngs/Interactable textures/Box.png");
    this->setTexture(*box);

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




#endif //METALCFU_BOX_H
