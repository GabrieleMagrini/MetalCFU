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

    explicit Map(int x = 10000, int y = 100, int g = 10) : sizeX(x), sizeY(y), gravity(g) {}
    ~Map() = default;

    int createMap(std::ifstream my_file);


    void gravityApply(int gravity, Player *player, Enemy *enemy, Weapon *weapon, Interactable *interactable);

private:
    int sizeX;
    int sizeY;
    int gravity;
    std::ifstream my_file;


};


#endif //METALCFU_MAP_H
