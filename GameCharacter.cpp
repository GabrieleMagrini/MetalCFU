//
// Created by emanuele on 23/05/19.
//

#include "GameCharacter.h"
#include "Weapon.h"

int GameCharacter::getHp() const {
    return HP;
}

void GameCharacter::setHp(int hp) {
    HP = hp;
}

int GameCharacter::getPosX() const {
    return posX;
}

void GameCharacter::setPosX(int posX) {
    GameCharacter::posX = posX;
}

int GameCharacter::getPosY() const {
    return posY;
}

void GameCharacter::setPosY(int posY) {
    GameCharacter::posY = posY;
}

int GameCharacter::getStrenght() const {
    return strenght;
}

void GameCharacter::setStrenght(int strenght) {
    GameCharacter::strenght = strenght;
}

int GameCharacter::getMovementSpeed() const {
    return movementSpeed;
}

void GameCharacter::setMovementSpeed(int movementSpeed) {
    GameCharacter::movementSpeed = movementSpeed;
}

void GameCharacter::move(int x, int y) {
    this->posX=x;
    this->posY=y;

}

void GameCharacter::setWeapon(Weapon* weapon) {
    this->weapon = weapon;
}



GameCharacter::GameCharacter(int hp, int x, int y, int s,Weapon * w, int ms): HP(hp), posX(x), posY(y), strenght(s),weapon(w), movementSpeed(ms){

}

