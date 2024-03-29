//
// Created by madmag on 07/07/19.
//

#ifndef METALCFU_TERRAINFACTORY_H
#define METALCFU_TERRAINFACTORY_H

#include "../Terrain.h"
#include <memory>

enum class TerrainType {
    Dirt, Water, Grass, Mud, Flag, Invisible
};


class TerrainFactory {
public:
    TerrainFactory() = default;

    virtual ~TerrainFactory() = default;

    std::unique_ptr<Terrain> createTerrain(TerrainType t, bool spawnPoint = false);

};


#endif //METALCFU_TERRAINFACTORY_H
