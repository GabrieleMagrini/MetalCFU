//
// Created by madmag on 22/06/19.
//

#ifndef METALCFU_MAP_H
#define METALCFU_MAP_H

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include <fstream>
#include <exception>

#include "Player.h"
#include "Enemy.h"
#include "Interactable.h"
#include "Weapon.h"
#include "Ammo.h"
#include "Terrain.h"
#include "Factory/TerrainFactory.h"


class Map {
public:
    ~Map() = default;

    std::vector<Terrain> createMap(std::ifstream my_file);


    void gravityApply(GameCharacter &g);


    explicit Map(int x = 14, int y = 51, int g = 10) : sizeX(x), sizeY(y), gravity(g) {}

    int getGravity() const;

    void setGravity(int gravity);

private:
    int sizeX;
    int sizeY;
    int gravity;


};


#endif //METALCFU_MAP_H
