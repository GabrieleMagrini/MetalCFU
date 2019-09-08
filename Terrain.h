//
// Created by madmag on 22/06/19.
//

#ifndef METALCFU_TERRAIN_H
#define METALCFU_TERRAIN_H

#include "GameCharacter.h"
#include "Ammo.h"
#include "Weapon.h"
#include "Interactable.h"



class Terrain :public Sprite{                                                                    //enum class,various types of block as various blocks effects
public:

    explicit Terrain(int s = 0, bool sp = false) : bonusSpeedMovement(s), spawnPoint(sp) {}

    ~Terrain() final = default;

    void checkCollision(
            GameCharacter &g);       //the block will have as only function to check the collision with the other elements

    int setBonus(GameCharacter &g);

    bool isSpawnPoint();

    void setSpawnPoint(bool spawnPoint);

private:
    int bonusSpeedMovement;
    bool spawnPoint;

};


#endif //METALCFU_TERRAIN_H
