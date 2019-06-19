//
// Created by emanuele on 14/06/19.
//

#ifndef METALCFU_INVENTORY_H
#define METALCFU_INVENTORY_H

#include <memory>
#include <vector>
#include "Weapon.h"

using namespace std;

template<typename T>
class Inventory {
public:
    explicit Inventory(int d = 4);

    Inventory(Inventory<T> &i);

    Inventory& operator=(const Inventory<T> &i);

    ~Inventory();

    T setElement(int i, T a);

    bool getElemet(int i, T &a);

    bool getElement(int i, Weapon &a);

    int getDim() const;

private:
    void copy(Inventory<T> &i);


    vector<T> buffer;
    vector<bool> usedElements;
    int dim;

};

template<typename T>
Inventory<T>::Inventory(int d): dim(d) {

    buffer = vector<T>(dim);
    for (int i = 0; i < dim; i++) {
        usedElements.push_back(false);
    }

}

/**
 * if an element is used, then we can over-write on the slot "i" of the vector, else we return the older element and we set the new element in the slot "i" of the vector
 * @tparam T
 * @param i
 * @param a
 * @return
 */
template<typename T>
T Inventory<T>::setElement(int i, T a) {
    if (i >= 0 && i < dim) {
        if (usedElements[i]) {
            usedElements[i] = false;
            buffer[i] = a;
            return;
        } else {
            T a = buffer[i];
            buffer[i] = a;
            return a;
        }
    }

    return;
}

/***
 * function that return an element of the vector in the parameter a if the element is not used.
 * @tparam T
 * @param i
 * @param a
 * @return true if the operation has been successful
 */
template<typename T>
bool Inventory<T>::getElemet(int i, T &a) {

    if (i >= 0 && i < dim) {
        if (!usedElements[i]) {
            usedElements[i] = true;
            a = buffer[i];

        }
    }
    return usedElements[i];
}

/***
 * function getElement for Weapon type, it should get the weapon always.
 * @param i
 * @param a
 * @return
 */
template<>
bool Inventory<Weapon>::getElement(int i, Weapon &a) {
    bool done = false;
    if (i >= 0 && i < dim) {
        a = buffer[i];
        done = true;
    }

    return done;
}

template<typename T>
int Inventory<T>::getDim() const {
    return dim;
}

template<typename T>
Inventory<T>::~Inventory() {
    delete[] buffer;
    delete[] usedElements;
}

template<typename T>
Inventory<T>::Inventory(Inventory<T> &i):dim(i.dim) {
    copy(i);
}

template<typename T>
Inventory<T>& Inventory<T>::operator=(const Inventory<T> &i) {
    dim=i.dim;
    copy(i);
    return *this;

}

template<typename T>
void Inventory<T>::copy(Inventory<T> &i) {
    buffer = vector<T>(dim);
    usedElements = vector<bool>(dim);
    for (int idx = 0; idx < dim; idx++) {
        buffer[idx] = i.buffer[idx];
        usedElements[idx] = i.usedElements[idx];
    }
}


#endif //METALCFU_INVENTORY_H
