//
// Created by emanuele on 01/08/19.
//

#ifndef METALCFU_CHARACTERANIMATION_H
#define METALCFU_CHARACTERANIMATION_H

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>
#include <SFML/Graphics/Texture.hpp>
#include "../GameCharacter.h"

class GameCharacter;

class CharacterAnimation {
public:
    explicit CharacterAnimation(const std::string &filename);

    ~CharacterAnimation() = default;

    void getTexture(GameCharacter &g, int pos, const std::string &direction = "right");

private:
    std::string filename;
    sf::Texture sheetTexture;
};


#endif //METALCFU_CHARACTERANIMATION_H
