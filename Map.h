//
// Created by madmag on 22/06/19.
//

#ifndef METALCFU_MAP_H
#define METALCFU_MAP_H

#include "GameCharacter.h"
#include "Interactable.h"
#include "Weapon.h"
#include "Ammo.h"
#include "Terrain.h"


class Map {

    explicit Map(int x=10000 ,int y=100) : sizeX(x),sizeY(y){}
    ~Map() = default;

    void createMap(TerrainType);

    void setPlayer(GameCharacter);

    void setEnemies(GameCharacter);

    void setInteractable(Interactable);

    void setObjects(Ammo,Weapon);



private:
    int sizeX;
    int sizeY;
};


#endif //METALCFU_MAP_H
