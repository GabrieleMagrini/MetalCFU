//
// Created by emanuele on 14/06/19.
//

#include "gtest/gtest.h"

#include "../MedKit.h"



TEST(MedKit,ConstructorTest){
   MedKit mk = MedKit{15};

   ASSERT_EQ(mk.use(),15);
}

TEST(MedKit,setHealerPoints){
    auto mk = new MedKit{4};
    mk->setHealerPoints(15);
    ASSERT_EQ(mk->use(),15);
    delete mk;
}