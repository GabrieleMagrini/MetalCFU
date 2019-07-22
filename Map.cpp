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
    std::unique_ptr<Terrain> mid = c.createTerrain(TerrainType::Dirt);
    std::unique_ptr<Terrain> grass = c.createTerrain(TerrainType::Grass);
    std::unique_ptr<Terrain> bot = c.createTerrain(TerrainType::Mud);

    auto gbounds = bot->getTexture()->getSize();
    std::vector<sf::Sprite> sprites;
    sprites.reserve(sizeX * sizeY);

    for (unsigned t = 0; t < sizeX; ++t) {
        for (unsigned z = 0; z < sizeY; ++z) {
            switch (map_array[t][z]) {
                case '1':
                    sprites.resize(sprites.size() + 1);
                    sprites.back().setTexture(*grass->getTexture());
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                case '0':
                    break;
                case '2':
                    sprites.resize(sprites.size() + 1);
                    sprites.back().setTexture(*mid->getTexture());
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                case '3':
                    sprites.resize(sprites.size() + 1);
                    sprites.back().setTexture(*bot->getTexture());
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                default:
                    break;
            }
        }
    }

    return sprites;
}


void Map::gravityApply(int gravity, Player *player, Enemy *enemy, Weapon *weapon, Interactable *interactable) {

    if (!player->getCollision())
        player->setSpeedY(gravity);
    else
        player->setSpeedY(0);
    if (!enemy->getCollision())
        enemy->setSpeedY(gravity);
    else
        enemy->setSpeedY(0);

}