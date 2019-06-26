//
// Created by emanuele on 19/06/19.
//

#include "gtest/gtest.h"

#include "../Weapon.h"


TEST(Weapon, WeaponConstructorTest) {

    auto w = new Weapon{};
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 0);
    ASSERT_EQ(w->getDamage(), 0);
    ASSERT_EQ(w->getRange(), 0);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), 0);


    Ammo curr{10};
    Ammo max{150};
    w = new Weapon{curr, 20, 15, max};

    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 10);
    ASSERT_EQ(w->getDamage(), 20);
    ASSERT_EQ(w->getRange(), 15);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), 150);

    w = new Weapon(20, 3, 15, 200);

    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 20);
    ASSERT_EQ(w->getDamage(), 3);
    ASSERT_EQ(w->getRange(), 15);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), 200);


    w = new Weapon{WeaponType::M4};

    ASSERT_EQ(w->getDamage(), 40);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 45);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), 300);
    ASSERT_EQ(w->getRange(), 15);

    w = new Weapon{WeaponType::pistol};

    ASSERT_EQ(w->getDamage(), 15);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), -1);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), -1);
    ASSERT_EQ(w->getRange(), 4);

    w = new Weapon{WeaponType::AK_47};

    ASSERT_EQ(w->getDamage(), 50);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 30);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), 250);
    ASSERT_EQ(w->getRange(), 10);

    w = new Weapon{WeaponType::AWP};

    ASSERT_EQ(w->getDamage(), 95);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 5);
    ASSERT_EQ(w->getMaxAmmo().getQuantity(), 20);
    ASSERT_EQ(w->getRange(), 30);

    delete w;
}

TEST(Weapon, ShootTest) {
    auto w = new Weapon(WeaponType::M4);

    ASSERT_EQ(w->shoot(), true);
    ASSERT_EQ(w->getCurrentAmmo().getQuantity(), 44);
}

