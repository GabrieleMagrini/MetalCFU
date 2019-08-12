//
// Created by madmag on 22/06/19.
//

#include "Map.h"

#include "Factory/TerrainFactory.h"


std::vector<Terrain> Map::createMap(std::ifstream my_file) {

    char map_array[sizeX][sizeY];


    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            my_file >> map_array[i][j];
        }
    }

    TerrainFactory c;
    std::unique_ptr<Terrain> bot = c.createTerrain(TerrainType::Mud);

    auto gbounds = bot->getTexture()->getSize();
    std::vector<Terrain> sprites;
    sprites.reserve(sizeX * sizeY);

    for (unsigned t = 0; t < sizeX; ++t) {
        for (unsigned z = 0; z < sizeY; ++z) {
            switch (map_array[t][z]) {
                case '1': {
                    sprites.resize(sprites.size() + 1);
                    sprites.push_back(*c.createTerrain(TerrainType::Grass));
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                }
                case '0': {
                    break;
                }
                case '2': {
                    sprites.resize(sprites.size() + 1);
                    sprites.push_back(*c.createTerrain(TerrainType::Dirt));
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                }
                case '3': {
                    sprites.resize(sprites.size() + 1);
                    sprites.push_back(*c.createTerrain(TerrainType::Mud));
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                }
                case 'x': {
                    sprites.resize(sprites.size() + 1);
                    sprites.push_back(*c.createTerrain(TerrainType::Invisible));
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                }
                default:
                    break;
            }
        }
    }

    return sprites;
}


void Map::gravityApply(GameCharacter &g) {
    if (!g.isCollisionDown())
        g.setPosition(g.getPosX(), g.getPosY() - gravity);
    //TODO
}

int Map::getGravity() const {
    return gravity;
}

void Map::setGravity(int gravity) {
    Map::gravity = gravity;
}
