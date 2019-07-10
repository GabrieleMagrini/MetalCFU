//
// Created by madmag on 22/06/19.
//

#include "Map.h"


int Map::createMap(std::ifstream my_file) {

    char map_array[sizeX][sizeY];


    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            my_file >> map_array[i][j];
        }
    }

    sf::Texture groundTex;
    if (!groundTex.loadFromFile("Sources/Pngs/tile.png"))
        return 0;
    sf::Texture dirt;
    if (!dirt.loadFromFile("Sources/Pngs/dirt.png"))
        return 0;
    sf::Texture bot;
    if (!bot.loadFromFile("Sources/Pngs/bottom.png"))
        return 0;

    auto gbounds = groundTex.getSize();
    std::vector<sf::Sprite> sprites;
    sprites.reserve(sizeX * sizeY);

    for (unsigned t = 0; t < sizeX; ++t) {
        for (unsigned z = 0; z < sizeY; ++z) {
            switch (map_array[t][z]) {
                case '1':
                    sprites.resize(sprites.size() + 1);
                    sprites.back().setTexture(groundTex);
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                case '0':
                    break;
                case '2':
                    sprites.resize(sprites.size() + 1);
                    sprites.back().setTexture(dirt);
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                    break;
                case '3':
                    sprites.resize(sprites.size() + 1);
                    sprites.back().setTexture(bot);
                    sprites.back().setPosition({gbounds.x * float(z), gbounds.y * float(t)});
                default:
                    break;
            }
        }
    }

    return 1;
}