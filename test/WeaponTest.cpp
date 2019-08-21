//
// Created by emanuele on 19/06/19.
//

#include "gtest/gtest.h"

#include "../Weapon.h"


TEST(Weapon, WeaponConstructorTest) {

    auto w = new Weapon{};
    ASSERT_EQ(w->getCurrentAmmo().size(), 0);
    ASSERT_EQ(w->getDamage(), 0);
    ASSERT_EQ(w->getRange(), 0);
    ASSERT_EQ(w->getMaxAmmo(), 0);
    ASSERT_EQ(w->getBulletSpeed(), 10);

}

TEST(Weapon, ShootTest) {
    auto w = new Weapon{10, 20, 15, 15};
    auto pos = Vector2f(10, 10);
    auto pos2 = Vector2f(15, 15);

//    ASSERT_EQ(w->shoot(pos, pos2), true);
    //  ASSERT_EQ(w->getCurrentAmmo().size(), 9);
}

TEST(Weapon, equalTest){
    auto w1 = new Weapon{10,20,15,15};
    auto w2 = new Weapon{10,21,15,15};
    ASSERT_EQ(*w1==*w2,false);

    w2= new Weapon{10,20,15,15};

    ASSERT_EQ(*w1==*w2,true);
}

