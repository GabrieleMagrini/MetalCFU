//
// Created by emanuele on 03/06/19.
//

#include "Interactable.h"

Interactable::Interactable(int x, int y, bool c, int sy) : posX(x), posY(y), collision(c), speedY(sy) {}


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

int Interactable::getSpeedY() const {
    return speedY;
}

void Interactable::setSpeedY(int speedY) {
    Interactable::speedY = speedY;
}
