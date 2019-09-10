//
// Created by madmag on 12/06/19.
//

#ifndef METALCFU_PLAYER_H
#define METALCFU_PLAYER_H

#include <list>

#include "GameCharacter.h"
#include "Inventory.h"
#include "Achievement/Subject.h"
#include "Achievement/Observer.h"

class Player : virtual public GameCharacter, public Subject {
public:

    explicit Player(int l, Weapon *w, Usable *u = nullptr, int hp = 100, int s = 20, int x = 10, int y = 10) : lives(l),
                                                                                                               GameCharacter(hp, x, y, s, w,
                                                                                                                             u,
                                                                                                                             4,
                                                                                                                             4,
                                                                                                                             10, -10, 0, 4,
                                                                                                                             false,
                                                                                                                             "Sources/Pngs/player textures/playerTexture.bmp") {}
    ~Player()override = default;


    int getLives() const;

    void setLives(int lives);

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;

private:
    int lives;

    std::list<Observer *> observers;
};




#endif //METALCFU_PLAYER_H
