//
// Created by madmag on 12/06/19.
//

#include "Player.h"

int Player::getLives() const {
    return lives;
}

void Player::setLives(int lives) {
    Player::lives = lives;
}

void Player::subscribe(Observer *o) {
    observers.push_back(o);
}

void Player::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Player::notify() {
    if (!observers.empty())
        for (auto obs = observers.begin(); obs != observers.end() && !observers.empty(); obs++) {
            (*obs)->update();
        }
}

Player::Player(int l, Weapon *w, Usable *u, int hp, int s, int x, int y) :
        lives(l),
        GameCharacter(hp, x, y, s, w, u, 4, 4, 10, 10, 0, 4, false,
                      "Sources/Pngs/player textures/playerTexture.bmp"), achievement("") {


}

void Player::unlock(AchievementType ac) {
    switch (ac) {
        case AchievementType::DISTANCE: {
            achievement = Achievement{"Do you like running?"};
            achievement.restartTimer();
            break;
        }
        case AchievementType::KILL: {
            achievement = Achievement{"Homicidal fury"};
            break;
        }
        case AchievementType::WIN: {
            achievement = Achievement{"Masterpiece"};
            break;
        }
        default:
            achievement = Achievement{""};
            break;
    }
}

void Player::renderAchiev(sf::RenderWindow &rw) {
    if (achievement.getText() != "") {
        achievement.render(rw);
    }
}