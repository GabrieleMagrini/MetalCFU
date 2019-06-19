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

    Inventory &operator=(const Inventory<T> &i);

    ~Inventory();

    T *setElement(int i, T a);

    bool removeElement(int i, T &a) const;

    T* getElement(int i) const;

    int getDim() const;

    bool setDim(int d);

    int getFirstFree() const;

private:
    void copy(Inventory<T> &i);


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
            return;
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
bool Inventory<T>::removeElement(int i, T &a) const{

    if (i >= 0 && i < dim) {
        if (usedSlot[i]) {
            usedSlot[i] = false;
            a = buffer[i];

        }
    }
    return !usedSlot[i];
}

template<typename T>
int Inventory<T>::getDim() const {
    return dim;
}

template<typename T>
Inventory<T>::~Inventory() {
    delete[] buffer;
    delete[] usedSlot;
}

template<typename T>
Inventory<T>::Inventory(Inventory<T> &i):dim(i.dim) {
    copy(i);
}

template<typename T>
Inventory<T> &Inventory<T>::operator=(const Inventory<T> &i) {
    dim = i.dim;
    copy(i);
    return *this;

}

template<typename T>
void Inventory<T>::copy(Inventory<T> &i) {
    buffer = vector<T>(dim);
    usedSlot = vector<bool>(dim);
    for (int idx = 0; idx < dim; idx++) {
        buffer[idx] = i.buffer[idx];
        usedSlot[idx] = i.usedSlot[idx];
    }
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
            buffer.push_back();
            usedSlot.push_back(false);
        }
        dim = d;
        done = true;
    }
    return done;
}

template<typename T>
int Inventory<T>::getFirstFree() const {
    for(int i=0;i<dim;i++)
        if(!usedSlot[i])
            return i;
}

template<typename T>
T* Inventory<T>::getElement(int i) const {
    if(i>=0 && i<dim){
        if(usedSlot[i])
            return new T{buffer[i]};
    }
}


#endif //METALCFU_INVENTORY_H
