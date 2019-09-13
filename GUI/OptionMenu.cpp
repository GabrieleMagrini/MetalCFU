//
// Created by emanuele on 26/07/19.
//

#include <cstring>

#include "OptionMenu.h"

/***
 *
 * @param rw RenderWindow
 * @param filename name of the background fiel
 * @param font of the Button
 */
OptionMenu::OptionMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &filename, const sf::Font &font)
        : renderWin(std::move(rw)), volumeOn(true), fullScreen(false), volInfo("On"), resInfo("1280x720"),
          resButton(renderWin->getSize().x / 2.0f + 10, 210, 100, 30, font, "1280x720",
                    "GUI/texture/idleGreenButton.png",
                    "GUI/texture/hoverGreenButton.png",
                    "GUI/texture/pressedGreenButton.png"),
          volButton(renderWin->getSize().x / 2.0f + 10, 100, 100, 30, font, "On", "GUI/texture/idleGreenButton.png",
                    "GUI/texture/hoverGreenButton.png",
                    "GUI/texture/pressedGreenButton.png"),
          cancelButton(renderWin->getSize().x / 2.0f + 5, 500, 80, 50, font, "Cancel",
                       "GUI/texture/idleGreenButton.png",
                       "GUI/texture/hoverGreenButton.png",
                       "GUI/texture/pressedGreenButton.png"),
          saveButton(renderWin->getSize().x / 2.0f - 85, 500, 80, 50, font, "Save", "GUI/texture/idleGreenButton.png",
                     "GUI/texture/hoverGreenButton.png",
                     "GUI/texture/pressedGreenButton.png") {

    onTextureIdle.loadFromFile("GUI/texture/idleGreenButton.png");
    onTextureHover.loadFromFile("GUI/texture/hoverGreenButton.png");
    onTexturePressed.loadFromFile("GUI/texture/pressedGreenButton.png");

    offTextureIdle.loadFromFile("GUI/texture/idleRedButton.png");
    offTextureHover.loadFromFile("GUI/texture/hoverRedButton.png");
    offTexturePressed.loadFromFile("GUI/texture/pressedRedButton.png");
    volumeTxt.setFont(font);
    volumeTxt.setString("Volume");
    volumeTxt.setCharacterSize(24);
    volumeTxt.setFillColor(sf::Color::Black);
    volumeTxt.setPosition(renderWin->getSize().x / 2.0f - volumeTxt.getLocalBounds().width, 100);

    resTxt.setFont(font);
    resTxt.setString("Resolution");
    resTxt.setCharacterSize(24);
    resTxt.setPosition(renderWin->getSize().x / 2.0f - resTxt.getLocalBounds().width, 210);
    resTxt.setFillColor(sf::Color::Black);
    resButton.setCharacterSize(17);

    backGrTexture.loadFromFile(filename);
    backGround.setTexture(backGrTexture);

    backGround.setPosition(0, 0);
    float scalex = static_cast<float>(renderWin->getSize().x) / static_cast<float>(backGrTexture.getSize().x);
    float scaley = static_cast<float>(renderWin->getSize().y) / static_cast<float>(backGrTexture.getSize().y);

    backGround.setScale(scalex, scaley);

    cancelButton.setCharacterSize(22);
    saveButton.setCharacterSize(22);
}

void OptionMenu::render() {
    renderWin->draw(backGround);

    renderWin->draw(volumeTxt);
    volButton.render(*renderWin);

    renderWin->draw(resTxt);
    resButton.render(*renderWin);
    saveButton.render(*renderWin);
    cancelButton.render(*renderWin);


    renderWin->display();

}

void OptionMenu::update() {
    backGround.setTextureRect(sf::IntRect(0, 0, static_cast<int>(renderWin->getView().getSize().x),
                                          static_cast<int>(renderWin->getView().getSize().y)));
    auto mousePos = sf::Mouse::getPosition(*renderWin);
    auto worldPos = renderWin->mapPixelToCoords(mousePos);

    volButton.update(worldPos);
    resButton.update(worldPos);
    saveButton.update(worldPos);
    cancelButton.update(worldPos);
}

bool OptionMenu::isVolumeButtonPressed() {
    return volButton.isPressed();
}

bool OptionMenu::isResButtonPressed() {
    return resButton.isPressed();
}

bool OptionMenu::isCancelButtonPressed() {
    return cancelButton.isPressed();
}

bool OptionMenu::isSaveButtonPressed() {
    return saveButton.isPressed();
}

/***
 * function that change the button color
 * @param release bool that will not do this function
 */
void OptionMenu::volumeButtonUpdate() {


        if (volumeOn) {
            volButton.setString("Off");
            volButton.setButtonTexture(offTextureIdle, offTextureHover, offTexturePressed);
            volumeOn = false;
        } else {
            volButton.setButtonTexture(onTextureIdle, onTextureHover, onTexturePressed);
            volButton.setString("On");
            volumeOn = true;
        }

}

/***
 * function that change the resolution of the button
 * @param release
 */
void OptionMenu::resButtonUpdate() {

    if (!fullScreen) {
        resButton.setString("FullScreen");
        fullScreen = true;
        } else {
            resButton.setString("1280x720");
        fullScreen = false;
        }

}

void OptionMenu::cancelButtonUpdate() {
    if (resInfo != resButton.getString()) {
        resButton.setString(resInfo);
    }
    if (volInfo != volButton.getString()) {
        volButton.setString(volInfo);
        if (volInfo == "On")
            volButton.setButtonTexture(onTextureIdle, onTextureHover, onTexturePressed);
        else
            volButton.setButtonTexture(offTextureIdle, offTextureHover, offTexturePressed);
    }
}

/***
 * function that save change in the resInfo and volInfo attributes, return change of resolution and true or false the volume is on or off
 * @param resolution
 * @param vol
 */
void OptionMenu::saveButtonUpdate(bool &resolution, bool &vol) {
    resolution = fullScreen;

    vol = volumeOn;
}
