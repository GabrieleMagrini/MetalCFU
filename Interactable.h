//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_INTERACTABLE_H
#define METALCFU_INTERACTABLE_H

#include <SFML/Graphics.hpp>

class Interactable : public sf::Sprite {
public:
    Interactable(int x, int y, bool c = false);

    ~Interactable() override = default;

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    void setCollision(bool v);

    bool getCollision();

private:

    int posX;
    int posY;
    bool collision;
};


#endif //METALCFU_INTERACTABLE_H
