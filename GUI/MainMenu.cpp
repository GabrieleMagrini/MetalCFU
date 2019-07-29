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
                                                                                                        (*renderWin).getSize().x /
                                                                                                        2.0f - 200, 100,
                                                                                                        400, 100,
                                                                                                        font,
                                                                                                        "Start",
                                                                                                        "GUI/texture/idleGreenButton.png",
                                                                                                        "GUI/texture/hoverGreenButton.png",
                                                                                                        "GUI/texture/pressedGreenButton.png"),

                                                                                                              optionButton(
                                                                                                        (*renderWin).getSize().x /
                                                                                                        2.0f - 200, 210,
                                                                                                        400, 100,
                                                                                                        font,
                                                                                                        "Option",
                                                                                                        "GUI/texture/idleGreenButton.png",
                                                                                                        "GUI/texture/hoverGreenButton.png",
                                                                                                        "GUI/texture/pressedGreenButton.png"),
                                                                                                              exitButton
                                                                                                        ((*renderWin).getSize().x /
                                                                                                         2.0f - 200,
                                                                                                         320,
                                                                                                         400, 100, font,
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
    float scalex = static_cast<float>((*renderWin).getSize().x) / static_cast<float>(backText.getSize().x);
    float scaley = static_cast<float>((*renderWin).getSize().x) / static_cast<float>(backText.getSize().x);

    backGround.setScale(scalex, scaley);
}

/***
 * function that draw all the button and background
 */
void MainMenu::render() {
    (*renderWin).draw(backGround);

    startButton.render(*renderWin);

    optionButton.render(*renderWin);

    exitButton.render(*renderWin);


    (*renderWin).display();
}

void MainMenu::update() {
    auto mousePos = sf::Mouse::getPosition(*renderWin);
    auto worldPos = (*renderWin).mapPixelToCoords(mousePos);
    startButton.update(worldPos);
    optionButton.update(worldPos);
    exitButton.update(worldPos);


}

bool MainMenu::exitButtonPressed() {
    return exitButton.isPressed();
}

bool MainMenu::optionButtonPressed() {
    return optionButton.isPressed();
}

bool MainMenu::startButtonPressed() {
    return startButton.isPressed();
}