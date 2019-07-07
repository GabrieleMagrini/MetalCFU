//
// Created by madmag on 22/06/19.
//

#include "Map.h"

void Map::createMap(Terrain g) {

    char map_array[sizeX][sizeY];


    for (int i=0;i<sizeX;++i){
        for (int j = 0;j<sizeY;++j) {
            my_file >> map_array[i][j];
        }
    }
    for (unsigned t = 0; t < sizeX; ++t) {
        for (unsigned z = 0; z < sizeY; ++z) {
            switch (map_array[t][z]) {
                case '1':
                    sprites.back().setTexture(g);
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                case '0':
                    break;
                default:break;
            }
        }
    }

}