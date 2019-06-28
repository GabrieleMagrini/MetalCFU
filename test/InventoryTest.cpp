//
// Created by emanuele on 28/06/19.
//

#include "gtest/gtest.h"

#include "../Inventory.h"

TEST(Inventory, int){
    Inventory<int> i;
    i.setElement(i.getFirstFree(),4);
    i.setElement(i.getFirstFree(),3);
    i.setElement(i.getFirstFree(),7);
    i.setElement(i.getFirstFree(),10);
    i.setElement(i.getFirstFree(),2);
    ASSERT_EQ(*i.getElement(0),4);
    ASSERT_EQ(*i.getElement(1),3);
    ASSERT_EQ(*i.getElement(2),7);
    ASSERT_EQ(*i.getElement(3),10);
    ASSERT_EQ(i.getElement(4),nullptr);
    int x;
    ASSERT_EQ(i.removeElement(4,x),false);
    ASSERT_EQ(i.removeElement(3,x),true);
    ASSERT_EQ(x,10);
}