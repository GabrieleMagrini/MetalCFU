//
// Created by emanuele on 01/07/19.
//

#include "gtest/gtest.h"

#include "../Ammo.h"

TEST(Ammo, constructor) {
    Ammo a{6};
    ASSERT_EQ(a.getQuantity(), 6);
}

TEST(Ammo, setQuatity) {
    Ammo a;
    ASSERT_EQ(a.getQuantity(), 1);
    a.setQuantity(15);
    ASSERT_EQ(a.getQuantity(), 15);
}

TEST(Ammo, equalOperator){
    Ammo a{3};
    Ammo a1;
    ASSERT_EQ(a==a1,false);
    a1.setQuantity(3);
    ASSERT_EQ(a==a1,true);
}