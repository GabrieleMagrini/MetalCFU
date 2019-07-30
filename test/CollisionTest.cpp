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

    block->checkCollision(player);

    ASSERT_EQ(player->getCollisionX(), true);


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

    block->checkCollision(player);

    ASSERT_EQ(player->getCollisionX(), false);


}


TEST(Collision, playerCollided) {
    TerrainFactory f;
    auto block = f.createTerrain(TerrainType::Dirt);

    block->setPosition(100, 100);

    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);

    auto player = new Player(2, w1.get());

    player->setPosition(52, 100);
    player->setTexture(*block->getTexture());

    block->checkCollision(player);

    ASSERT_EQ(player->getCollisionX(), true);


}


TEST(Collision, collisionY) {
    TerrainFactory f;
    auto block = f.createTerrain(TerrainType::Dirt);

    block->setPosition(100, 100);

    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);

    auto player = new Player(2, w1.get());

    player->setPosition(0, 100);
    player->setTexture(*block->getTexture());

    block->checkCollision(player);

    ASSERT_EQ(player->getCollisionY(), false);


}

