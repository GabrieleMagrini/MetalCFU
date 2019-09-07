//
// Created by madmag on 07/07/19.
//

#include "TerrainFactory.h"


std::unique_ptr<Terrain> TerrainFactory::createTerrain(TerrainType t, bool spawnPoint) {
    std::unique_ptr<Terrain> terrainResult;

    auto groundTex = new sf::Texture();
    groundTex->loadFromFile(
            "Sources/Pngs/tile.png");

    auto dirt = new sf::Texture();
    dirt->loadFromFile(
            "Sources/Pngs/mid.png");

    auto bot = new sf::Texture();
    bot->loadFromFile(
            "Sources/Pngs/bottom.png");

    auto invisible = new sf::Texture();
    invisible->loadFromFile(
            "Sources/Pngs/Invisible.png");

    switch (t) {
        case TerrainType::Dirt:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0, spawnPoint});
            terrainResult->setTexture(*dirt);
            break;
        case TerrainType::Water:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{-5, spawnPoint});
            break;
        case TerrainType::Grass:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{5, spawnPoint});
            terrainResult->setTexture(*groundTex);
            break;
        case TerrainType::Mud:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{-7, spawnPoint});
            terrainResult->setTexture(*bot);
            break;
        case TerrainType::Flag:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0, spawnPoint});
            break;
        case TerrainType::Invisible:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0, spawnPoint});
            terrainResult->setTexture(*invisible);
            break;

    }
    return terrainResult;
}