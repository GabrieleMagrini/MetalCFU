//
// Created by emanuele on 26/07/19.
//

#include "MainMenu.h"

/***
 *
 * @param rw a pointer to a RenderWindow
 * @param filename name of the file for the background
 */
MainMenu::MainMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &filename, const sf::Font &font) : renderWin(
        std::move(
                rw)),
                                                                                                              startButton(
                                                                                                                      renderWin->getSize().x /
                                                                                                                      2.0f -
                                                                                                                      200,
                                                                                                                      100,
                                                                                                                      400,
                                                                                                                      100,
                                                                                                                      font,
                                                                                                                      "Start",
                                                                                                                      "GUI/texture/idleGreenButton.png",
                                                                                                                      "GUI/texture/hoverGreenButton.png",
                                                                                                                      "GUI/texture/pressedGreenButton.png"),

                                                                                                              optionButton(
                                                                                                                      renderWin->getSize().x /
                                                                                                                      2.0f -
                                                                                                                      200,
                                                                                                                      210,
                                                                                                                      400,
                                                                                                                      100,
                                                                                                                      font,
                                                                                                                      "Option",
                                                                                                                      "GUI/texture/idleGreenButton.png",
                                                                                                                      "GUI/texture/hoverGreenButton.png",
                                                                                                                      "GUI/texture/pressedGreenButton.png"),
                                                                                                              exitButton
                                                                                                                      (renderWin->getSize().x /
                                                                                                                       2.0f -
                                                                                                                       200,
                                                                                                                       320,
                                                                                                                       400,
                                                                                                                       100,
                                                                                                                       font,
                                                                                                                       "Exit",
                                                                                                                       "GUI/texture/idleGreenButton.png",
                                                                                                                       "GUI/texture/hoverGreenButton.png",
                                                                                                                       "GUI/texture/pressedGreenButton.png") {
    //buttons
    startButton.setCharacterSize(40);
    optionButton.setCharacterSize(40);
    exitButton.setCharacterSize(40);

    //background
    if (!backText.loadFromFile(filename)) {

    }

    backGround.setTexture(backText);
    backGround.setPosition(0, 0);
    float scalex = static_cast<float>(renderWin->getSize().x) / static_cast<float>(backText.getSize().x);
    float scaley = static_cast<float>(renderWin->getSize().y) / static_cast<float>(backText.getSize().y);

    backGround.setScale(scalex, scaley);
}

/***
 * function that draw all the button and background
 */
void MainMenu::render() {
    renderWin->draw(backGround);

    startButton.render(*renderWin);

    optionButton.render(*renderWin);

    exitButton.render(*renderWin);


    renderWin->display();
}

void MainMenu::update() {
    backGround.setTextureRect(sf::IntRect(0, 0, renderWin->getSize().x, renderWin->getSize().y));
    float scaleX = static_cast<float>(renderWin->getView().getSize().x) / static_cast<float>(backText.getSize().x);
    float scaleY = static_cast<float>(renderWin->getView().getSize().y) / static_cast<float>(backText.getSize().y);

    backGround.setScale(scaleX, scaleY);
    auto mousePos = sf::Mouse::getPosition(*renderWin);
    auto worldPos = renderWin->mapPixelToCoords(mousePos);
    startButton.setPosition(renderWin->getView().getCenter().x - startButton.getShape().getSize().x / 2.0f, 100);
    startButton.update(worldPos);

    optionButton.setPosition(renderWin->getView().getCenter().x - optionButton.getShape().getSize().x / 2.0f, 205);
    optionButton.update(worldPos);

    exitButton.setPosition(renderWin->getView().getCenter().x - exitButton.getShape().getSize().x / 2.0f, 310);
    exitButton.update(worldPos);
}

bool MainMenu::isExitButtonPressed() {
    return exitButton.isPressed();
}

bool MainMenu::isOptionButtonPressed() {
    return optionButton.isPressed();
}

bool MainMenu::isStartButtonPressed() {
    return startButton.isPressed();
}