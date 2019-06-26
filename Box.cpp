//
// Created by emanuele on 26/06/19.
//

#include "Box.h"

Box::Box(Weapon *w, Ammo *a, Usable *u, Attachment *at, int x, int y, int hp) : Interactable(x, y), giftWeapon(w),
                                                                                giftAmmo(a), giftUsable(u),
                                                                                giftAttach(at), hp(hp) {

}
