//
// Created by madmag on 22/06/19.
//

#ifndef METALCFU_MAP_H
#define METALCFU_MAP_H

#include "Player.h"
#include "Enemy.h"
#include "Interactable.h"
#include "Weapon.h"
#include "Ammo.h"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <ctime>
#include <vector>
#include <fstream>


#include "Terrain.h"


class Map {
public:
    ~Map() = default;

    std::vector<Terrain> createMap(std::ifstream my_file);


    void gravityApply(int gravity, Player *player, Enemy *enemy);


    explicit Map(int x = 7, int y = 30, int g = 10) : sizeX(x), sizeY(y), gravity(g) {}

private:
    int sizeX;
    int sizeY;
    int gravity;


};


#endif //METALCFU_MAP_H
