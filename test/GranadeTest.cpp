//
// Created by emanuele on 14/06/19.
//

#include "gtest/gtest.h"

#include "../Granade.h"



TEST(Granade,contructorTest){
    auto g = new Granade{45, 5};
    ASSERT_EQ(g->getExplosionTime(), 5);
    delete g;
}

TEST(Granade, updateTemp) {
    auto g = new Granade{45, 5};
    g->setExplosionTime(25);
    ASSERT_EQ(g->getExplosionTime(), 25);
    delete g;
}