//
// Created by emanuele on 23/05/19.
//

#include "GameCharacter.h"
#include "Usable.h"
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

/***
 * move the player in the map
 * @param x axis
 * @param y axis
 */
void GameCharacter::move(int x, int y) {
    this->posX = x;
    this->posY = y;

}

/***
 * set a Weapon to the weaponInventory in the first free slot
 * @param weapon the weapon to add
 * @return true if the operation has been successful, false if the inventory is full
 */
bool GameCharacter::setWeapon(Weapon *weapon) {
    bool isNotFull = false;
    for (int i = 0; i < maxWeapon && !isNotFull; i++) {
        if (this->weaponInventory[i] == nullptr) {
            this->weaponInventory[i] = weapon;
            isNotFull = true;
        }
    }
    return isNotFull;
}

/**
 *
 * @param idx index of the slot of the inventory
 * @return a pointer to an Usable
 */
Usable *GameCharacter::getUsable(int idx) const {
    if (idx < 0 || idx >= usableInventory.size())
        return nullptr;
    else
        return usableInventory[idx];
}

/***
 * set an usable in the "usable" inventory
 * @param usable the usable to insert in the inventory
 * @return true if the operation has been successful, false if the inventory is full
 */
bool GameCharacter::setUsable(Usable *usable) {
    bool isNotFull = false;
    for (int i = 0; i < this->usableInventory.size() && !isNotFull; i++) {
        if (this->usableInventory[i] == nullptr) {
            this->usableInventory[i] = usable;
            isNotFull = true;
        }
    }
    return isNotFull;
}

int GameCharacter::getMaxWeapon() const {
    return this->maxWeapon;
}

void GameCharacter::setMaxWeapon(int maxWeapon) {
    GameCharacter::maxWeapon = maxWeapon;
}

/**
 * @param idx number of the slot
 * @return a pointer to a weapon in the "idx" slot
 */
const Weapon *GameCharacter::getWeapon(int idx) const {

    if (idx < 0 || idx >= maxWeapon)
        return nullptr;
    else
        return weaponInventory[idx];

}
/**
 * remove a weapon from the inventory
 * @param idx index of the slot
 * @return the weapon
 */
Weapon *GameCharacter::removeWeapon(int idx) {
    if (idx < 0 || idx >= maxWeapon)
        return nullptr;
    else {
        Weapon *w = weaponInventory[idx];
        weaponInventory.erase(weaponInventory.begin() + idx);
        return w;
    }


}
/**
 * remove an Usable from the inventory
 * @param idx index of the slot
 * @return the Usable
 */
Usable *GameCharacter::removeUsable(int idx) {
    if (idx < 0 || idx > usableInventory.size())
        return nullptr;
    else {
        Usable *u = usableInventory[idx];
        usableInventory.erase(usableInventory.begin() + idx);
        return u;
    }
}
/**
 * function that drop from the inventory of the GameCharacter to the map any Weapon or Usable
 * the object will save in the parameters list
 * @param wi dropped weapon inventory
 * @param ui dropped Usable inventory
 */
void GameCharacter::releaseInventory(std::vector<Weapon *> &wi, std::vector<Usable *> &ui) {
    for(int i=0;i<maxWeapon;i++){
        wi.push_back(*weaponInventory.erase((weaponInventory.begin()+i)));
    }

    for(int i=0;i<maxUsable;i++){
        ui.push_back(*usableInventory.erase(usableInventory.begin()+i));
    }
}

GameCharacter::GameCharacter(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw, int mu, int ms,int sw): HP(hp), posX(x), posY(y), strenght(s), maxWeapon(mw), maxUsable(mu), movementSpeed(ms), selectedWeapon(sw) {
    weaponInventory.push_back(w);
    usableInventory.push_back(p);
}

int GameCharacter::getMaxUsable() const {
    return maxUsable;
}

void GameCharacter::setMaxUsable(int maxUsable) {
    GameCharacter::maxUsable = maxUsable;
}

bool GameCharacter::isTwoGameCharacterNearby(GameCharacter *gc1, GameCharacter *gc2) {
    bool b=false;
    if(abs(gc1->getPosX()-gc2->getPosX())<=1 && abs(gc1->getPosY()-gc2->getPosY())<=1)
        b=true;
    return b;
}

int GameCharacter::getSelectedWeapon() const {
    return selectedWeapon;
}

void GameCharacter::setSelectedWeapon(int selectedWeapon) {
    GameCharacter::selectedWeapon = selectedWeapon;
}

const std::vector<Weapon *> &GameCharacter::getWeaponInventory() const {
    return weaponInventory;
}

void GameCharacter::setWeaponInventory(const std::vector<Weapon *> &weaponInventory) {
    GameCharacter::weaponInventory = weaponInventory;
}

const std::vector<Usable *> &GameCharacter::getUsableInventory() const {
    return usableInventory;
}
void GameCharacter::setUsableInventory(const std::vector<Usable *> &usableInventory) {
    GameCharacter::usableInventory = usableInventory;
}

/**
 * function that take the damage from "damage" and calculate the new HP
 * @param damage
 */
void GameCharacter::getDamage(unsigned int damage) {
    HP=HP-damage;

    if(HP<=0) {
        HP = 0;
    }
}

void GameCharacter::fight(GameCharacter *enemy) {
    if(isTwoGameCharacterNearby(this,enemy)){
        enemy->getDamage(this->strenght);
    } else{
        weaponInventory[selectedWeapon]->shoot();
    }
}