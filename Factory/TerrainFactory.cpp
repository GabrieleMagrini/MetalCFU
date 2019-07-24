//
// Created by madmag on 07/07/19.
//

#include "TerrainFactory.h"


std::unique_ptr<Terrain> TerrainFactory::createTerrain(TerrainType t) {
    std::unique_ptr<Terrain> terrainResult;

    auto groundTex = new sf::Texture();
    groundTex->loadFromFile(
            "/home/madmag/Desktop/UniFi/Programmazione/Progetto/Sources/Pngs/tile.png");

    auto dirt = new sf::Texture();
    dirt->loadFromFile(
            "/home/madmag/Desktop/UniFi/Programmazione/Progetto/Sources/Pngs/mid.png");

    auto bot = new sf::Texture();
    bot->loadFromFile(
            "/home/madmag/Desktop/UniFi/Programmazione/Progetto/Sources/Pngs/bottom.png");

    switch (t) {
        case TerrainType::Dirt:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0});
            terrainResult->setTexture(*dirt);
            break;
        case TerrainType::Water:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{-5});
            break;
        case TerrainType::Grass:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{5});
            terrainResult->setTexture(*groundTex);
            break;
        case TerrainType::Mud:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{-7});
            terrainResult->setTexture(*bot);
            break;
        case TerrainType::Flag:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0});
    }
    return terrainResult;
}