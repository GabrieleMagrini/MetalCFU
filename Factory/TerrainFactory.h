//
// Created by madmag on 07/07/19.
//

#ifndef METALCFU_TERRAINFACTORY_H
#define METALCFU_TERRAINFACTORY_H

#include "../Terrain.h"
#include <memory>

enum class TerrainType{
    Dirt,Water,Grass,Mud,Flag
};


class TerrainFactory {
public:
    TerrainFactory() = default;

    virtual ~TerrainFactory() = default;

    virtual std::unique_ptr<Terrain> createTerrain(TerrainType t);

};


#endif //METALCFU_TERRAINFACTORY_H
