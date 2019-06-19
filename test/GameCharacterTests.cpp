//
// Created by emanuele on 05/06/19.
//

#include "gtest/gtest.h"
#include "../GameCharacter.h"

TEST(GameCharacter, Constructor) {

        auto c = new GameCharacter(20, 0, 0, 10, nullptr, nullptr);

        ASSERT_EQ(c->getHp(), 20);
        ASSERT_EQ(c->getPosX(), 0);
        ASSERT_EQ(c->getPosY(), 0);
        ASSERT_EQ(c->getStrenght(), 10);
        ASSERT_EQ(c->getWeapon(), nullptr);
        ASSERT_EQ(c->getUsable(0), nullptr);
        ASSERT_EQ(c->getDimWeapon(), 4);
        ASSERT_EQ(c->getDimUsable(), 4);
        ASSERT_EQ(c->getMovementSpeed(), 10);

        c = new GameCharacter(20, 0, 0, 10, nullptr, nullptr, 5, 2, 20);
        ASSERT_EQ(c->getDimWeapon(), 5);
        ASSERT_EQ(c->getDimUsable(), 2);
        ASSERT_EQ(c->getMovementSpeed(), 20);
        delete c;

}

TEST(GameCharacter, positionUpdate) {


        auto c = new GameCharacter(20, 0, 0, 10, nullptr, nullptr);
        c->setPosX(5);
        ASSERT_EQ(c->getPosX(), 5);
        c->setPosY(5);
        ASSERT_EQ(c->getPosY(), 5);

        c->move(12, 12);
        ASSERT_EQ(c->getPosX(), 12);
        ASSERT_EQ(c->getPosY(), 12);

}

TEST(GameCharacter, hpUpdate) {

        auto c = new GameCharacter(20, 0, 0, 10, nullptr, nullptr);
        c->setHp(100);
        ASSERT_EQ(c->getHp(), 100);

}

TEST(GameCharacter, movementSpeedupdate) {

        auto c = GameCharacter(20, 0, 0, 10, nullptr, nullptr);
        ASSERT_EQ(c.getMovementSpeed(),10);
        c.setMovementSpeed(20);
        ASSERT_EQ(c.getMovementSpeed(),20);
}

TEST(GameCharacter, isTwoGameCharacterNearby) {

        auto c = new GameCharacter(20, 0, 0, 10, nullptr, nullptr);
        auto b = new GameCharacter(20, 0, 0, 10, nullptr, nullptr);
        c->move(1, 0);
        ASSERT_EQ(GameCharacter::isTwoGameCharacterNearby(c, b), true);
        c->move(1, 1);

        ASSERT_EQ(GameCharacter::isTwoGameCharacterNearby(c, b), true);
        c->move(2, 3);

        ASSERT_EQ(GameCharacter::isTwoGameCharacterNearby(c, b), false);

}

TEST(GameCharacter, getDamage){
    auto c = GameCharacter(20, 0, 0, 10, nullptr, nullptr);
    c.getDamage(10);
    ASSERT_EQ(c.getHp(),10);
}