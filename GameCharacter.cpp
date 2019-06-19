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
 * set a Weapon to the weaponInventory in the first free slot or in a selected slot, the new weapon replace the older, this one will drop in the map.
 * @param weapon the weapon to add
 * @return true if the operation has been successful, false if the inventory is full
 */
Weapon * GameCharacter::setWeapon(Weapon *weapon) {
    bool isNotFull = false;
    Weapon* w= nullptr;

    for (int i = 0; i < maxWeapon && !isNotFull; i++) {
        if (this->weaponInventory[i] == nullptr) {
            this->weaponInventory[i] = weapon;
            isNotFull = true;
        }
    }
    if(!isNotFull){
       w= weaponInventory[selectedWeapon];
       weaponInventory[selectedWeapon]=weapon;
    }
    return w;
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
 * set an usable in the "usable" inventory in a free slot or in the selectedSlot
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
 *
 * @return a pointer to a weapon in the selected slot
 */
const Weapon *GameCharacter::getWeapon() const {

        return weaponInventory[selectedWeapon];

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

GameCharacter::GameCharacter(int hp, int x, int y, int s, Weapon *w, Usable *p, int mw, int mu, int ms, int sw): HP(hp), posX(x), posY(y), strenght(s),
movementSpeed(ms), selectedWeapon(sw), weaponInventory(mw),usableInventory(mu){
   weaponInventory.setElement(0,*w);
   usableInventory.setElement(0,p);
}

int GameCharacter::getDimUsable() const {
    return usableInventory.getDim();
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
/**
 * function that: if the enemy is nearby, player will do melee attack, else he fire with the gun.
 * @param enemy
 */
void GameCharacter::fight(GameCharacter *enemy) {
    if(isTwoGameCharacterNearby(this,enemy)){
        enemy->getDamage(this->strenght);
    } else{
        weaponInventory[selectedWeapon]->shoot();
    }
}
/***
 * function that use the usable at slot "invIdx"
 * @param invIdx
 */
void GameCharacter::useUsable(int invIdx) {
    if(invIdx>=0 && invIdx<maxUsable){
        if(auto mk=dynamic_cast<MedKit*>(usableInventory[invIdx])){
            HP=HP+mk->use();
            usableInventory.erase(usableInventory.begin() +invIdx);
        }

    }else if(auto g= dynamic_cast<Granade*>(usableInventory[invIdx])){
        g->use();
        usableInventory.erase(usableInventory.begin() +invIdx);
    }

}
/**
 * function that change an usable, in the "idx" slot, with usable
 * @param usable pointer to an usable
 * @param idx the slot
 * @return the older usable
 */
Usable *GameCharacter::changeUsable(Usable *usable, int idx) {
    Usable * u= nullptr;
    if(idx>0 && idx<maxUsable) {
        u= usableInventory[idx];
        usableInventory[idx]=usable;

    }
    return u;
}