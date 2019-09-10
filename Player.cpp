//
// Created by madmag on 12/06/19.
//

#include "Player.h"

int Player::getLives() const {
    return lives;
}

void Player::setLives(int lives) {
    Player::lives = lives;
}

void Player::subscribe(Observer *o) {
    observers.push_back(o);
}

void Player::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Player::notify() {
    for (auto &obs: observers) {
        obs->update();
    }
}

Player::Player(int l, Weapon *w, Usable *u, int hp, int s, int x, int y) : lives(l),
                                                                           GameCharacter(hp, x, y, s, w, u, 4, 4, 10,
                                                                                         -10, 0, 4, false,
                                                                                         "Sources/Pngs/player textures/playerTexture.bmp") {

}