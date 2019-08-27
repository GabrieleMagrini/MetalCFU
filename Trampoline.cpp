//
// Created by emanuele on 03/06/19.
//

#include "Trampoline.h"
#include "Player.h"

Trampoline::Trampoline(int h) : height(h) {
    auto trampoline = new sf::Texture();
    trampoline->loadFromFile(
            "Sources/Pngs/Interactable textures/Trampoline.png");
    this->setTexture(*trampoline);

}

//The function is called until the bool value "liftUp" get value "false"
void Trampoline::liftUp(Player *player) {
    if (abs(player->getPosY() - this->getPosition().y) < height)
        player->setPosition(player->getPosX(), player->getPosY() + 1);
}
