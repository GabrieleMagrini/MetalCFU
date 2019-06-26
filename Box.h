//
// Created by emanuele on 26/06/19.
//

#ifndef METALCFU_BOX_H
#define METALCFU_BOX_H

#include <memory>

#include "Weapon.h"
#include "Usable.h"
#include "Attachment.h"
#include "Interactable.h"

using namespace std;

class Box : public Interactable {
public:
    Box(Weapon *w, Ammo *a, Usable *u, Attachment *at, int x, int y, int hp = 100);

    ~Box() override = default;

private:
    unique_ptr<Weapon> giftWeapon;
    unique_ptr<Ammo> giftAmmo;
    unique_ptr<Usable> giftUsable;
    unique_ptr<Attachment> giftAttach;
    int hp;
};


#endif //METALCFU_BOX_H
