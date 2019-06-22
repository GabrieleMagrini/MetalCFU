//
// Created by madmag on 22/06/19.
//

#ifndef METALCFU_TERRAIN_H
#define METALCFU_TERRAIN_H

#include "GameCharacter.h"
#include "Ammo.h"
#include "Weapon.h"
#include "Interactable.h"



enum class TerrainType{Dirt,Water,Grass};

class Terrain {                                                                    //enum class,various types of block as various blocks effects
public:
    Terrain();

    explicit Terrain(int s = 10):bonusSpeedMovement(s){}

    explicit Terrain(TerrainType type);

    virtual ~Terrain() = default;

    int checkCollision(GameCharacter,Ammo,Weapon,Interactable);       //the block will have as only function to check the collision with the other elements

    int setBonus(GameCharacter,int bonusSpeedMovement);


private:
    int bonusSpeedMovement;
};


#endif //METALCFU_TERRAIN_H
