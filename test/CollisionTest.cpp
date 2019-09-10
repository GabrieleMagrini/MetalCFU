//
// Created by madmag on 25/07/19.
//


#include "gtest/gtest.h"

#include "../Terrain.h"
#include "../Factory/TerrainFactory.h"
#include "../Player.h"
#include "../Factory/WeaponFactory.h"




TEST(Collision, playerCollision) {
    TerrainFactory f;
    auto block = f.createTerrain(TerrainType::Dirt);

    block->setPosition(100, 100);

    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);

    auto player = new Player(2, w1.get());

    player->setPosition(100, 100);
    player->setTexture(*block->getTexture());

    block->checkCollision(*player);

    ASSERT_EQ(player->isCollisionDown(), false);

    ASSERT_EQ(player->isCollisionLeft(), false);

    ASSERT_EQ(player->isCollisionUp(), false);

    ASSERT_EQ(player->isCollisionRight(), true);



}


TEST(Collision, playerNotCollided) {
    TerrainFactory f;
    auto block = f.createTerrain(TerrainType::Dirt);

    block->setPosition(100, 100);

    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);

    auto player = new Player(2, w1.get());

    player->setPosition(0, 100);
    player->setTexture(*block->getTexture());

    block->checkCollision(*player);

    ASSERT_EQ(player->isCollisionDown(), false);

    ASSERT_EQ(player->isCollisionLeft(), false);

    ASSERT_EQ(player->isCollisionUp(), false);

    ASSERT_EQ(player->isCollisionRight(), false);


}


TEST(Collision, playerCollided) {
    TerrainFactory f;
    auto block = f.createTerrain(TerrainType::Dirt);
    auto block2 = f.createTerrain(TerrainType::Dirt);

    block->setPosition(60, 100);
    block2->setPosition(50, 100);

    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);

    auto player = new Player(2, w1.get());

    player->setPosition(52, 100);
    player->setTexture(*block->getTexture());

    block->checkCollision(*player);
    block2->checkCollision(*player);


    ASSERT_EQ(player->isCollisionLeft(), false);

    ASSERT_EQ(player->isCollisionUp(), false);

    ASSERT_EQ(player->isCollisionRight(), true);


}
