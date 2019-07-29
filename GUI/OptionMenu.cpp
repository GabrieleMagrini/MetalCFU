//
// Created by emanuele on 26/07/19.
//

#include "OptionMenu.h"

/***
 *
 * @param rw RenderWindow
 * @param filename name of the background fiel
 * @param font of the Button
 */
OptionMenu::OptionMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &filename, const sf::Font &font)
        : renderWin(std::move(rw)),
          resButton((*renderWin).getSize().x / 2.0f + 10, 210, 50, 30, font, "1280x720",
                    "GUI/texture/idleGreenButton.png",
                    "GUI/texture/hoverGreenButton.png",
                    "GUI/texture/pressedGreenButton.png"),
          volButton((*renderWin).getSize().x / 2.0f + 10, 100, 50, 30, font, "On", "GUI/texture/idleGreenButton.png",
                    "GUI/texture/hoverGreenButton.png",
                    "GUI/texture/pressedGreenButton.png"),
          cancelButton((*renderWin).getSize().x / 2.0f, 500, 70, 50, font, "Cancel", "GUI/texture/idleGreenButton.png",
                       "GUI/texture/hoverGreenButton.png",
                       "GUI/texture/pressedGreenButton.png"),
          saveButton((*renderWin).getSize().x / 2.0f - 80, 500, 70, 50, font, "Save", "GUI/texture/idleGreenButton.png",
                     "GUI/texture/hoverGreenButton.png",
                     "GUI/texture/pressedGreenButton.png") {

    onTextureIdle.loadFromFile("GUI/texture/idleGreenButton.png");
    onTextureHover.loadFromFile("GUI/texture/hoverGreenButton.png");
    onTexturePressed.loadFromFile("GUI/texture/pressedGreenButton.png");

    offTextureidle.loadFromFile("GUI/texture/idleRedButton.png");
    offTextureHover.loadFromFile("GUI/texture/hoverRedButton.png");
    offTexturePressed.loadFromFile("GUI/texture/pressedRedButton.png");

    volumeTxt.setString("Volume");
    volumeTxt.setCharacterSize(24);
    volumeTxt.setPosition((*renderWin).getSize().x / 2.0f - volumeTxt.getLocalBounds().width, 100);


    resTxt.setString("Resolution");
    resTxt.setCharacterSize(24);
    resTxt.setPosition((*renderWin).getSize().x / 2.0f - resTxt.getLocalBounds().width, 210);

    backGrTexture.loadFromFile(filename);
    backGround.setTexture(backGrTexture);

    backGround.setPosition(0, 0);
    float scalex = static_cast<float>((*renderWin).getSize().x) / static_cast<float>(backGrTexture.getSize().x);
    float scaley = static_cast<float>((*renderWin).getSize().x) / static_cast<float>(backGrTexture.getSize().x);

    backGround.setScale(scalex, scaley);
}

void OptionMenu::render() {
    (*renderWin).draw(backGround);

    (*renderWin).draw(volumeTxt);
    volButton.render(*renderWin);

    (*renderWin).draw(resTxt);
    resButton.render(*renderWin);
    saveButton.render(*renderWin);
    cancelButton.render(*renderWin);


    (*renderWin).display();

}