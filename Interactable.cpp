//
// Created by emanuele on 03/06/19.
//

#include "Interactable.h"

Interactable::Interactable(int x, int y, bool c) : posX(x), posY(y), collision(c) {}


int Interactable::getPosX() const {
    return posX;
}

void Interactable::setPosX(int posX) {
    Interactable::posX = posX;
}

int Interactable::getPosY() const {
    return posY;
}

void Interactable::setPosY(int posY) {
    Interactable::posY = posY;
}

void Interactable::setCollision(bool v) {
    collision = v;
}

bool Interactable::getCollision() {
    return collision;
}