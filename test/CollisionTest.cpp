//
// Created by madmag on 25/07/19.
//


#include "gtest/gtest.h"
#include "../Collision.h"
#include "../Terrain.h"
#include "../Factory/TerrainFactory.h"
#include "../Player.h"
#include "../Factory/WeaponFactory.h"


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