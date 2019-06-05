//
// Created by emanuele on 05/06/19.
//

#include "gtest/gtest.h"
#include "../GameCharacter.h"

TEST(GameCharacter,Constructor){

    auto c = new GameCharacter(20,0,0,10,nullptr,nullptr);

    ASSERT_EQ(c->getHp(),20);
    ASSERT_EQ(c->getPosX(),0);
    ASSERT_EQ(c->getPosY(),0);
    ASSERT_EQ(c->getStrenght(),10);
    ASSERT_EQ(c->getWeapon(0), nullptr);
    ASSERT_EQ(c->getUsable(0), nullptr);
    ASSERT_EQ(c->getMaxWeapon(),4);
    ASSERT_EQ(c->getMaxUsable(),4);
    ASSERT_EQ(c->getMovementSpeed(),10);
    delete c;
}
