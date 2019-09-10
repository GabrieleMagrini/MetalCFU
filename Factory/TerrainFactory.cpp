//
// Created by madmag on 07/07/19.
//

#include "TerrainFactory.h"


std::unique_ptr<Terrain> TerrainFactory::createTerrain(TerrainType t, bool spawnPoint) {
    std::unique_ptr<Terrain> terrainResult;
    switch (t) {
        case TerrainType::Dirt:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0, spawnPoint, "Sources/Pngs/mid.png"});
            break;
        case TerrainType::Water:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{-5, spawnPoint});
            break;
        case TerrainType::Grass:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{5, spawnPoint, "Sources/Pngs/tile.png"});
            break;
        case TerrainType::Mud:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{-7, spawnPoint, "Sources/Pngs/bottom.png"});
            break;
        case TerrainType::Flag:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0, spawnPoint});
            break;
        case TerrainType::Invisible:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0, spawnPoint, "Sources/Pngs/Invisible.png"});
            break;

    }
    return terrainResult;
}