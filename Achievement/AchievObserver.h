//
// Created by emanuele on 10/09/19.
//

#ifndef METALCFU_ACHIEVOBSERVER_H
#define METALCFU_ACHIEVOBSERVER_H

#include "SFML/Graphics.hpp"

#include "Observer.h"
#include "../Player.h"

class player;

class AchievObserver : public Observer, public sf::Sprite {
public:
    explicit AchievObserver(Player *p, shared_ptr<sf::RenderWindow> rw, const std::string &text,
                            const std::string &filename = "Sources/Pngs/trophy.png");


    void attach() override;

    void detach() override;

    void render(sf::RenderWindow *rw);

protected:
    std::shared_ptr<Player> subject;
    bool doneAchieve;
private:
    std::shared_ptr<sf::Texture> texture;
    sf::Text text;

};


#endif //METALCFU_ACHIEVOBSERVER_H
