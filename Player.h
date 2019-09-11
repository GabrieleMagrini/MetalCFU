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
#include "Achievement/Achievement.h"

enum class AchievementType {
    DISTANCE, KILL, WIN
};

class Player : virtual public GameCharacter, public Subject {
public:

    explicit Player(int l, Weapon *w, Usable *u = nullptr, int hp = 100, int s = 20, int x = 10, int y = 10);
    ~Player()override = default;


    int getLives() const;

    void setLives(int lives);

    void subscribe(Observer *o) override;

    void unsubscribe(Observer *o) override;

    void notify() override;

    void unlock(AchievementType at);

    void renderAchiev(sf::RenderWindow &rw);

private:
    int lives;
    std::list<Observer *> observers;
    Achievement achievement;
};




#endif //METALCFU_PLAYER_H
