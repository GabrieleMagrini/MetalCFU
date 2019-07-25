//
// Created by madmag on 25/07/19.
//


#include "gtest/gtest.h"
#include "../Collision.h"
#include "../Terrain.h"
#include "../Factory/TerrainFactory.h"
#include "../Player.h"


TEST(Collision, blockCollision) {
    TerrainFactory f;
    auto block = f.createTerrain(TerrainType::Dirt);
    auto block2 = f.createTerrain(TerrainType::Dirt);

    Sprite sprite1;
    Sprite sprite2;

    sprite1.setTexture(*block->getTexture());
    sprite2.setTexture(*block->getTexture());

    sprite1.setPosition(100, 100);
    sprite2.setPosition(100, 100);

    ASSERT_EQ(Collision::PixelPerfectTest(sprite1, sprite2), true);

}
