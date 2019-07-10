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

    explicit Map(int x=10000 ,int y=100) : sizeX(x),sizeY(y){}
    ~Map() = default;

    int createMap(std::ifstream my_file);

    void setPlayer(Player *player);

    void setEnemies();

    void setInteractable(Enemy *enemy);

    void setObjects(Ammo *ammo,Weapon *weapon);


    char loadFiles();


private:
    int sizeX;
    int sizeY;
    std::ifstream my_file;


};


#endif //METALCFU_MAP_H
