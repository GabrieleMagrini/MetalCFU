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
    explicit Map(int x = 16, int y = 51, int g = 10) : sizeX(x), sizeY(y), gravity(g) {}

    ~Map() = default;

    void readValues(std::ifstream *my_file);

    std::vector<Terrain> createMap(std::ifstream my_file);

    void gravityApply(GameCharacter &g);

    int getGravity() const;

    void setGravity(int gravity);

    int getSizeX() const;

    void setSizeX(int sizeX);

    int getSizeY() const;

    void setSizeY(int sizeY);

private:
    int sizeX;
    int sizeY;
    int gravity;

};


#endif //METALCFU_MAP_H
