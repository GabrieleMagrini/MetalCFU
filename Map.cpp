//
// Created by madmag on 22/06/19.
//

#include "Map.h"
#include "Factory/TerrainFactory.h"


std::vector<sf::Sprite> Map::createMap(std::ifstream my_file) {

    char map_array[sizeX][sizeY];


    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            my_file >> map_array[i][j];
        }
    }

    TerrainFactory c;
    std::unique_ptr<Terrain> bot = c.createTerrain(TerrainType::Mud);

    auto gbounds = bot->getTexture()->getSize();
    std::vector<Sprite> sprites;
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
                default:
                    break;
            }
        }
    }

    return sprites;
}


void Map::gravityApply(int gravity, Player *player, Enemy *enemy) {

    float oldPosY = player->getPosY();
    player->setPosition(player->getPosX(), player->getPosY() - gravity);
    if (player->getCollisionY())
        player->setPosition(player->getPosX(), oldPosY);

}