//
// Created by emanuele on 14/06/19.
//

#include "gtest/gtest.h"

#include "../MedKit.h"



TEST(MedKit,constructorTest){
    MedKit mk;

    ASSERT_EQ(mk.getData(), 45);
}

TEST(MedKit,setHealerPoints){
    auto mk = new MedKit{};
    mk->setData(15);
    ASSERT_EQ(mk->getData(), 15);
    delete mk;
}