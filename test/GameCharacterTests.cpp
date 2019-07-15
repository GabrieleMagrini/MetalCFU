//
// Created by emanuele on 05/06/19.
//

#include "gtest/gtest.h"
#include "../GameCharacter.h"
#include "../Factory/WeaponFactory.h"
#include "../MedKit.h"
#include "../Granade.h"


TEST(GameCharacter, Constructor) {

    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);
    auto c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);

    ASSERT_EQ(c->getHp(), 20);
    ASSERT_EQ(c->getPosX(), 0);
    ASSERT_EQ(c->getPosY(), 0);
    ASSERT_EQ(c->getStrenght(), 10);
    ASSERT_EQ((*w1) == c->getWeapon(), true);
    ASSERT_EQ(c->getUsable(0), nullptr);
    ASSERT_EQ(c->getDimWeapon(), 4);
    ASSERT_EQ(c->getDimUsable(), 4);
    ASSERT_EQ(c->getSpeedY(), 10);

    c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr, 5, 2, 20);
    ASSERT_EQ(c->getDimWeapon(), 5);
    ASSERT_EQ(c->getDimUsable(), 2);
    ASSERT_EQ(c->getSpeedY(), 20);
    delete c;

}

TEST(GameCharacter, positionUpdate) {
    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);

    auto c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);
    c->teleport(5, c->getPosY());
    ASSERT_EQ(c->getPosX(), 5);
    c->teleport(c->getPosX(), 5);
    ASSERT_EQ(c->getPosY(), 5);

    c->teleport(12, 12);
    ASSERT_EQ(c->getPosX(), 12);
    ASSERT_EQ(c->getPosY(), 12);

}

TEST(GameCharacter, hpUpdate) {
    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);
    auto c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);
    c->setHp(100);
    ASSERT_EQ(c->getHp(), 100);

}

TEST(GameCharacter, movementSpeedupdate) {
    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);
    auto c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);
    ASSERT_EQ(c->getSpeedY(), 10);
    c->setSpeedY(20);
    ASSERT_EQ(c->getSpeedY(), 20);
}

TEST(GameCharacter, isTwoGameCharacterNearby) {
    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);
    auto c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);
    auto b = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);
    c->teleport(1, 0);
    ASSERT_EQ(GameCharacter::isTwoGameCharacterNearby(c, b), true);
    c->teleport(1, 1);

    ASSERT_EQ(GameCharacter::isTwoGameCharacterNearby(c, b), true);
    c->teleport(2, 3);

    ASSERT_EQ(GameCharacter::isTwoGameCharacterNearby(c, b), false);

}

TEST(GameCharacter, getDamage) {
    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);
    auto c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);
    c->getDamage(10);
    ASSERT_EQ(c->getHp(), 10);
}

TEST(GameCharacter, releaseInventory) {

    WeaponFactory w;
    auto w1 = w.createWeapon(WeaponType::pistol);
    auto w2 = w.createWeapon(WeaponType::AWP);

    Usable *u1 = new MedKit{10};
    Usable *u2 = new Granade{15};
    auto gc = new GameCharacter{20, 0, 0, 10, w1.get(), u1};
    auto u3 = gc->setUsable(u2);
    ASSERT_EQ(u3, nullptr);
    auto w3 = gc->setWeapon(w2.get());
    ASSERT_EQ(w3, nullptr);

    const Inventory<Weapon> iw = gc->getWeaponInventory();
    const Inventory<Usable *> iu = gc->getUsableInventory();

    Inventory<Weapon> iw2(4);
    Inventory<Usable *> iu2(4);

    gc->releaseInventory(iw2, iu2);

    ASSERT_EQ(iw, iw2);
    ASSERT_EQ(iu, iu2);

}

TEST(GameCharacter, strenghtUpdate) {
    WeaponFactory w;

    auto w1 = w.createWeapon(WeaponType::M4);
    auto c = new GameCharacter(20, 0, 0, 10, w1.get(), nullptr);

    c->setStrenght(26);
    ASSERT_EQ(c->getStrenght(), 26);
}