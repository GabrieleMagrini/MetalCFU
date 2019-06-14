//
// Created by emanuele on 14/06/19.
//

#include "gtest/gtest.h"

#include "../Granade.h"



TEST(Granade,contructorTest){
    auto g= new Granade{45};
    ASSERT_EQ(g->getDamage(),45);
    g->setDamage(25);
    ASSERT_EQ(g->getDamage(),25);
    delete g;
}

TEST(Granade,updateDamage){
    auto g= new Granade{45};
    g->setDamage(25);
    ASSERT_EQ(g->getDamage(),25);
    delete g;
}