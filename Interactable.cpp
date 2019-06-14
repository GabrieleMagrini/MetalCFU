//
// Created by emanuele on 03/06/19.
//

#include "Interactable.h"

Interactable::Interactable( int x, int y):posX(x), posY(y){}


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
