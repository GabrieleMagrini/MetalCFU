//
// Created by emanuele on 19/06/19.
//

#include "gtest/gtest.h"

#include "../Weapon.h"


TEST(Weapon,WeaponConstructor) {
    auto w = new Weapon{WeaponType::M4};

    ASSERT_EQ(w->getDamage(), 40);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 45);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), 300);
    ASSERT_EQ(w->getRange(), 15);

    w = new Weapon{WeaponType::pistol};

    ASSERT_EQ(w->getDamage(), 15);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 4);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), -1);
    ASSERT_EQ(w->getRange(), -1);

    w = new Weapon{WeaponType::AK_47};

    ASSERT_EQ(w->getDamage(),50);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(),10);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(),250);
    ASSERT_EQ(w->getRange(),30);

    w = new Weapon{WeaponType::AWP};

    ASSERT_EQ(w->getDamage(),95);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(),30);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(),20);
    ASSERT_EQ(w->getRange(),5);
}