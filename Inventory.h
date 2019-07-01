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

    Inventory(const Inventory<T> &i);

    Inventory &operator=(const Inventory<T> &i);

    bool operator==(Inventory<T> i) const;

    ~Inventory();

    T *setElement(int i, T a);

    bool removeElement(int i, T &a);

    T *getElement(int i) const;

    int getDim() const;

    bool setDim(int d);

    int getFirstFree() const;

private:


    vector<T> buffer;
    vector<bool> usedSlot;
    int dim;

};

template<typename T>
Inventory<T>::Inventory(int d): dim(d) {

    buffer = vector<T>(dim);
    for (int i = 0; i < dim; i++) {
        usedSlot.push_back(false);
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
T *Inventory<T>::setElement(int i, T a) {
    T *ab = nullptr;
    if (i >= 0 && i < dim) {
        if (!usedSlot[i]) {
            usedSlot[i] = true;
            buffer[i] = a;
        } else {
            ab = new T{buffer[i]};
            buffer[i] = a;
        }
    }

    return ab;
}

/***
 * function that return an element of the vector in the parameter a if the element is not used and remove it from the inventory
 * @tparam T
 * @param i
 * @param a
 * @return true if the operation has been successful
 */
template<typename T>
bool Inventory<T>::removeElement(int i, T &a) {
    bool done = false;
    if (i >= 0 && i < dim) {
        if (usedSlot[i]) {
            usedSlot[i] = false;
            a = buffer[i];
            done = true;
        }
    }
    return done;
}

template<typename T>
int Inventory<T>::getDim() const {
    return dim;
}

template<typename T>
Inventory<T>::~Inventory() = default;

template<typename T>
Inventory<T>::Inventory(const Inventory<T> &i):dim(i.dim) {
    buffer = vector<T>(dim);
    usedSlot = vector<bool>(dim);
    for (int idx = 0; idx < dim; idx++) {
        buffer[idx] = i.buffer[idx];
        usedSlot[idx] = i.usedSlot[idx];
    }
}

template<typename T>
Inventory<T> &Inventory<T>::operator=(const Inventory<T> &i) {
    dim = i.dim;
    buffer = vector<T>(dim);
    usedSlot = vector<bool>(dim);
    for (int idx = 0; idx < dim; idx++) {
        buffer[idx] = i.buffer[idx];
        usedSlot[idx] = i.usedSlot[idx];
    }
    return *this;
}

/**
 * method that can incraese the dimension of the inventory
 * @tparam T
 * @param d
 * @return true if the dimension is incresed
 */
template<typename T>
bool Inventory<T>::setDim(int d) {
    bool done = false;
    if (d > dim) {
        for (int i = dim; i < d; i++) {
            buffer.push_back(T{});
            usedSlot.push_back(false);
        }
        dim = d;
        done = true;
    }
    return done;
}

template<typename T>
int Inventory<T>::getFirstFree() const {
    int i;
    for (i = 0; i < usedSlot.size(); i++)
        if (!usedSlot[i])
            break;
    return i;
}

template<typename T>
T *Inventory<T>::getElement(int i) const {
    if (i >= 0 && i < dim) {
        if (usedSlot[i])
            return new T{buffer[i]};
    }
    return nullptr;
}

template<typename T>
bool Inventory<T>::operator==(const Inventory<T> i) const {
    int idx = 0;
    bool isEqual = false;
    if (dim == i.dim)
        while (idx < dim) {
            if (usedSlot[idx] != i.usedSlot[idx]) {
                break;
            }
            if (usedSlot[idx])
                if (!(buffer[idx] == i.buffer[idx]))
                    break;

            idx++;

        }
    if (idx >= dim)
        isEqual = true;

    return isEqual;
}


#endif //METALCFU_INVENTORY_H
