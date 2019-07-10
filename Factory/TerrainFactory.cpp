//
// Created by madmag on 07/07/19.
//

#include "TerrainFactory.h"


std::unique_ptr<Terrain> TerrainFactory::createTerrain(TerrainType t) {
    std::unique_ptr<Terrain> terrainResult;
    switch (t) {
        case TerrainType::Dirt:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{0});
            break;
        case TerrainType::Water:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{-5});
            break;
        case TerrainType::Grass:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{5});
            break;
        case TerrainType ::Mud:
            terrainResult = std::unique_ptr<Terrain> (new Terrain{-7});
            break;
        case TerrainType ::Flag:
            terrainResult = std::unique_ptr<Terrain>(new Terrain{0});
    }
};