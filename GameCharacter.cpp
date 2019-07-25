//
// Created by emanuele on 23/05/19.
//

#include "GameCharacter.h"
#include "Usable.h"
#include "Weapon.h"
#include "MedKit.h"
#include "Granade.h"

int GameCharacter::getHp() const {
    return HP;
}

void GameCharacter::setHp(int hp) {
    HP = hp;
}

float GameCharacter::getPosX() const {
    return getPosition().x;
}


float GameCharacter::getPosY() const {
    return getPosition().y;
}

int GameCharacter::getStrenght() const {
    return strenght;
}

void GameCharacter::setStrenght(int strenght) {
    GameCharacter::strenght = strenght;
}

int GameCharacter::getSpeedX() const {
    return SpeedX;
}

void GameCharacter::setSpeedX(int SpeedX) {
    GameCharacter::SpeedX = SpeedX;
}

int GameCharacter::getSpeedY() const {
    return SpeedY;
}

void GameCharacter::setSpeedY(int SpeedY) {
    GameCharacter::SpeedY = SpeedY;
}
/***
 * teleport the player in the map in the coordinated
 * @param x axis
 * @param y axis
 */
void GameCharacter::teleport(float x, float y) {
    setPosition(x, y);
}

/***
 * set a Weapon to the weaponInventory in the first free slot or in a selected slot, the new weapon replace the older, this one will drop in the map.
 * @param weapon the weapon to add
 * @return true if the operation has been successful, false if the inventory is full
 */
Weapon *GameCharacter::setWeapon(Weapon *weapon) {
    Weapon *w = nullptr;
    int i = weaponInventory.getFirstFree();

    if (i == weaponInventory.getDim())
        weaponInventory.setElement(selectedWeapon, *weapon);
    else
        w = weaponInventory.setElement(i, *weapon);
    return w;
}

/**
 *
 * @param idx index of the slot of the inventory
 * @return a pointer to an Usable
 */
Usable *GameCharacter::getUsable(int idx) const {
    Usable *us = nullptr;
    if (idx >= 0 && idx < usableInventory.getDim())
        us = *usableInventory.getElement(idx);
    return us;
}

/***
 * set an usable to the usableInventory in the first free slot or in a selected slot, the new usable replace the older, this one will drop in the map.
 * @param usable the usable to insert in the inventory
 * @return true if the operation has been successful, false if the inventory is full
 */
Usable *GameCharacter::setUsable(Usable *usable) {
    Usable **u = nullptr;
    int i = usableInventory.getFirstFree();
    if (i == usableInventory.getDim())
        u = usableInventory.setElement(selectedUsable, usable);
    else
        u = usableInventory.setElement(i, usable);
    if (u == nullptr)
        return nullptr;

    return *u;
}

int GameCharacter::getDimWeapon() const {
    return weaponInventory.getDim();
}

void GameCharacter::setDimWeapon(int dw) {
    weaponInventory.setDim(dw);
}

/**
 *
 * @return  a weapon in the selected slot
 */
Weapon GameCharacter::getWeapon() const {
    Weapon a;
    a = *weaponInventory.getElement(selectedWeapon);
    return a;

}

/**
 * remove a weapon from the inventory
 * @param idx index of the slot
 * @return the weapon
 */
Weapon *GameCharacter::removeWeapon(int idx) {
    Weapon a;
    if (idx >= 0 && idx < usableInventory.getDim()) {
        weaponInventory.removeElement(idx, a);
        if (a.getDamage() > 0)
            return new Weapon(a);
    }
    return nullptr;
}

/**
 * remove an Usable from the inventory
 * @param idx index of the slot
 * @return the Usable
 */
Usable *GameCharacter::removeUsable(int idx) {
    Usable *u = nullptr;
    if (idx > 0 && idx < usableInventory.getDim())
        usableInventory.removeElement(idx, u);

    return u;
}

/**
 * function that drop from the inventory of the GameCharacter to the map any Weapon or Usable
 * the object will save in the parameters list
 * @param wi dropped weapon inventory
 * @param ui dropped Usable inventory
 */
void GameCharacter::releaseInventory(Inventory<Weapon> &wi, Inventory<Usable *> &ui) {
    wi = Inventory<Weapon>{weaponInventory.getDim()};
    ui = Inventory<Usable *>{usableInventory.getDim()};
    Weapon w;
    for (int i = 0; i < weaponInventory.getDim(); i++) {
        if (weaponInventory.removeElement(i, w))
            wi.setElement(i, w);
    }

    Usable *u;

    for (int i = 0; i < usableInventory.getDim(); i++) {
        if (usableInventory.removeElement(i, u))
            ui.setElement(i, u);
    }
}

GameCharacter::GameCharacter(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw, int mu, int sx, int sy, int sw,
                             int su,
                             Texture *txt, bool c)
        : HP(hp), strenght(s),
          SpeedX(sx), SpeedY(sy), selectedWeapon(sw), weaponInventory(mw), usableInventory(mu), selectedUsable(su),
          collisionX(c), collisionY(c) {
    weaponInventory.setElement(0, *w);
    usableInventory.setElement(0, p);
    setPosition(x, y);
    if (txt != nullptr)
        setTexture(*txt);
}

int GameCharacter::getDimUsable() const {
    return usableInventory.getDim();
}

void GameCharacter::setDimUsable(int ud) {
    usableInventory.setDim(ud);
}

bool GameCharacter::isTwoGameCharacterNearby(GameCharacter *gc1, GameCharacter *gc2) {
    bool b = false;
    if (abs(gc1->getPosX() - gc2->getPosX()) <= 1 && abs(gc1->getPosY() - gc2->getPosY()) <= 1)
        b = true;
    return b;
}

int GameCharacter::getSelectedWeapon() const {
    return selectedWeapon;
}

void GameCharacter::setSelectedWeapon(int selectedWeapon) {
    GameCharacter::selectedWeapon = selectedWeapon;
}

const Inventory<Weapon> &GameCharacter::getWeaponInventory() const {
    return weaponInventory;
}

void GameCharacter::setWeaponInventory(const Inventory<Weapon> &weaponInventory) {
    GameCharacter::weaponInventory = weaponInventory;
}

const Inventory<Usable *> &GameCharacter::getUsableInventory() const {
    return usableInventory;
}

void GameCharacter::setUsableInventory(const Inventory<Usable *> &usableInventory) {
    GameCharacter::usableInventory = usableInventory;
}

/**
 * function that take the damage from "damage" and calculate the new HP
 * @param damage
 */
void GameCharacter::getDamage(unsigned int damage) {
    HP = HP - damage;

    if (HP <= 0) {
        HP = 0;
    }
}

/**
 * function that: if the enemy is nearby, player will do melee attack, else he fire with the gun.
 * @param enemy
 */
void GameCharacter::fight(GameCharacter *enemy) {
    if (isTwoGameCharacterNearby(this, enemy)) {
        enemy->getDamage(this->strenght);
    } else {
        weaponInventory.getElement(selectedWeapon)->shoot();
    }
}

/***
 * function that use the usable at slot "invIdx"
 * @param invIdx
 */
void GameCharacter::useUsable(int invIdx) {
    Usable *u = nullptr;
    usableInventory.removeElement(invIdx, u);
    if (u != nullptr)
        u->use();
}

/**
 * funzione che effettua lo spostamento del personaggio
 * @param direction direzione sui 4 assi su cui spostarsi
 */
void GameCharacter::move(int direction) {
    /*
     * do{
     * if (direction == 0)
        setPosition(getPosX(), getPosY() + movementSpeed);
    if (direction == 1)
        setPosition(getPosX() + movementSpeed, getPosY());
    if (direction == 3)
        setPosition(getPosX() - movementSpeed, getPosY());
        int oldPosX = posX;
        }while(!collisionX)
        if (collisionX)
        setPosition(oldPosx);
*/
}


void GameCharacter::setCollisionX(bool v) {
    collisionX = v;
}

bool GameCharacter::getCollisionX() {
    return collisionX;
}

void GameCharacter::setCollisionY(bool v) {
    collisionY = v;
}

bool GameCharacter::getCollisionY() {
    return collisionY;
}