//
// Created by madmag on 07/07/19.
//

#include "TerrainFactory.h"


std::unique_ptr<Terrain> TerrainFactory::createTerrain(TerrainType t) {
    std::unique_ptr<Terrain> terrainResult;
    sf::Texture groundTex;
    groundTex.loadFromFile("Sources/Pngs/tile.png");
    sf::Texture dirt;
    dirt.loadFromFile("Sources/Pngs/dirt.png");
    sf::Texture bot;
    bot.loadFromFile("Sources/Pngs/bottom.png");
    switch (t) {
        case TerrainType::Dirt:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{0});
            terrainResult->setTexture(dirt);
            break;
        case TerrainType::Water:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{-5});
            break;
        case TerrainType::Grass:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{5});
            terrainResult->setTexture(groundTex);
            break;
        case TerrainType ::Mud:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{-7});
            terrainResult->setTexture(bot);
            break;
        case TerrainType ::Flag:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0});
    }
    return terrainResult;
};