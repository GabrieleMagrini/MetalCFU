//
// Created by emanuele on 25/06/19.
//

#include "gtest/gtest.h"

#include "../Attachment/Attachment.h"
#include "../Weapon.h"
#include "../Attachment/ExtendedMagazine.h"
#include "../Attachment/LongBarrel.h"
#include "../Attachment/PowerBarrel.h"
#include "../Attachment/LaserScope.h"
#include "../Factory/WeaponFactory.h"


TEST(Attachment, AttachmentConstructorTest) {
    //test for ExtendedMagazine
    ExtendedMagazine mg;
    ASSERT_EQ(mg.getImprovement(), 30);
    mg = ExtendedMagazine{40};
    ASSERT_EQ(mg.getImprovement(), 40);

    //test for LongBarrel
    LongBarrel b = LongBarrel{20};
    ASSERT_EQ(b.getImprovement(), 20);
    b = LongBarrel{};
    ASSERT_EQ(b.getImprovement(), 15);

    //test for PowerBarrel
    PowerBarrel pb = PowerBarrel{};
    ASSERT_EQ(pb.getImprovement(), 8);
    pb = PowerBarrel{10};
    ASSERT_EQ(pb.getImprovement(), 10);

}

TEST(Attachment, ImprovementTest) {
    WeaponFactory w;

    auto w1 = *(w.createWeapon(WeaponType::M4));
    ExtendedMagazine mg;

    mg.improve(w1);
    ASSERT_EQ(w1.getMaxAmmo(), 400);

    PowerBarrel pb;
    pb.improve(w1);
    ASSERT_EQ(w1.getDamage(), 43);

    LaserScope sc;
    sc.improve(w1);
    ASSERT_EQ(w1.isActiveLaser(), true);

    LongBarrel lb = LongBarrel(15);
    lb.improve(w1);
    ASSERT_EQ(w1.getRange(), 15);
}