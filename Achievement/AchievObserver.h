//
// Created by emanuele on 10/09/19.
//

#ifndef METALCFU_ACHIEVOBSERVER_H
#define METALCFU_ACHIEVOBSERVER_H

#include "SFML/Graphics.hpp"

#include "Observer.h"
#include "../Player.h"

class AchievObserver : public Observer, public sf::Sprite {
public:
    explicit AchievObserver(Player *p, shared_ptr<sf::RenderWindow> rw, const std::string &text,
                            const std::string &filename = "Sources/Pngs/trophy.png");

    void update() override;

    void attach() override;

    void detach() override;

    void render();

private:
    std::shared_ptr<Player> subject;

    std::shared_ptr<sf::Texture> texture;
    std::shared_ptr<sf::RenderWindow> renderWin;
    sf::Text text;

};


#endif //METALCFU_ACHIEVOBSERVER_H
