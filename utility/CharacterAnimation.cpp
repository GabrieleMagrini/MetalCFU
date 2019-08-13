//
// Created by emanuele on 01/08/19.
//

#include "CharacterAnimation.h"

/***
 * open a file that contain all the texture of a character
 * @param filename
 */
CharacterAnimation::CharacterAnimation(const std::string &filename) : filename(filename) {
    if (!sheetTexture.loadFromFile(filename)) {
        std::cerr << "ERRORE - impossibile accedere al file" << "endl";
    }


}

void CharacterAnimation::getTexture(GameCharacter &g, int pos, const std::string &direction) {
    sf::IntRect rectTexture;
    if (direction == "right")
        rectTexture = sf::IntRect(1 * pos + 36 * pos + 1, 1, 36, 60);
    else
        rectTexture = sf::IntRect(1 * pos + 36 * pos + 1, 65, 36, 60);


    g.setTexture(sheetTexture);
    g.setTextureRect(rectTexture);
}
