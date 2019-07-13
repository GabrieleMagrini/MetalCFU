//
// Created by emanuele on 26/05/19.
//

#include "Ammo.h"

int Ammo::getQuantity() const {
    return quantity;
}

void Ammo::setQuantity(int quantity) {
    Ammo::quantity = quantity;
}

bool Ammo::operator==(const Ammo &a2) const{
    bool us = false;
    if (quantity == a2.quantity)
        us = true;
    return us;
}

void Ammo::setCollision(bool v) {
    collision = v;
}