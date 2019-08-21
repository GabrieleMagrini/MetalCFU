//
// Created by emanuele on 01/07/19.
//

#include "gtest/gtest.h"

#include "../Ammo.h"

TEST(Ammo, constructor) {
    Ammo a{6, 4, false, false};
    ASSERT_EQ(a.getDamage(), 6);
    ASSERT_EQ(a.getRange(), 4);
    ASSERT_EQ(a.getTerrainCollision(), false);
    ASSERT_EQ(a.isIsShot(), false);
    auto b = a;
    ASSERT_EQ(b.getDamage(), 6);
    ASSERT_EQ(b.getRange(), 4);
    ASSERT_EQ(b.getTerrainCollision(), false);
    ASSERT_EQ(b.isIsShot(), false);
}

TEST(Ammo, setDamage) {
    Ammo a;
    ASSERT_EQ(a.getDamage(), 1);
    a.setDamage(15);
    ASSERT_EQ(a.getDamage(), 15);
}

TEST(Ammo, equalOperator){
    Ammo a{3};
    Ammo a1;
    ASSERT_EQ(a==a1,false);
    a1.setDamage(3);
    ASSERT_EQ(a==a1,true);
}

TEST(Ammo, setRange) {
    Ammo a;
    a.setRange(10);
    ASSERT_EQ(a.getRange(), 10);
}