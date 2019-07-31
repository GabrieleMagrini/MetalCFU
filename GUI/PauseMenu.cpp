//
// Created by emanuele on 31/07/19.
//

#include "PauseMenu.h"

PauseMenu::PauseMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &imageFileName, const sf::Font &font)
        : renderWin(std::move(rw)), backGameButton(renderWin->getSize().x / 2.0f - 200, 100,
                                                   400, 100,
                                                   font,
                                                   "Back to Game",
                                                   "GUI/texture/idleGreenButton.png",
                                                   "GUI/texture/hoverGreenButton.png",
                                                   "GUI/texture/pressedGreenButton.png"),

          mainMenuButton(renderWin->getSize().x / 2.0f - 200, 100,
                         400, 100,
                         font,
                         "Start",
                         "GUI/texture/idleGreenButton.png",
                         "GUI/texture/hoverGreenButton.png",
                         "GUI/texture/pressedGreenButton.png") {
    textBackGround.loadFromFile(imageFileName);
    backGround.setTexture(textBackGround);
    backGround.setPosition(0, 0);
    float scalex = static_cast<float>(renderWin->getSize().x) / static_cast<float>(textBackGround.getSize().x);
    float scaley = static_cast<float>(renderWin->getSize().y) / static_cast<float>(textBackGround.getSize().y);

    backGround.setScale(scalex, scaley);
}

void PauseMenu::update() {
    auto mousePos = sf::Mouse::getPosition(*renderWin);
    auto worldPos = renderWin->mapPixelToCoords(mousePos);
    mainMenuButton.update(worldPos);
    backGameButton.update(worldPos);
}

void PauseMenu::render() {
    renderWin->draw(backGround);
    mainMenuButton.render((*renderWin));
    backGameButton.render((*renderWin));

    (*renderWin).display();
}

bool PauseMenu::isBackGameButtonPressed() {
    return backGameButton.isPressed();
}

bool PauseMenu::isMainMenuButtonPressed() {
    return mainMenuButton.isPressed();
}

void PauseMenu::setTextureBackGround(const sf::Texture &texture) {
    textBackGround = texture;

    backGround.setTexture(textBackGround);
    backGround.setPosition(0, 0);
    float scalex = static_cast<float>(renderWin->getSize().x) / static_cast<float>(textBackGround.getSize().x);
    float scaley = static_cast<float>(renderWin->getSize().y) / static_cast<float>(textBackGround.getSize().y);

    backGround.setScale(scalex, scaley);

}
