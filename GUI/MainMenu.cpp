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
                                                                                                                       "GUI/texture/pressedGreenButton.png"),
                                                                                                              nextLevel(
                                                                                                                      false) {
    //buttons
    startButton.setCharacterSize(40);
    optionButton.setCharacterSize(40);
    exitButton.setCharacterSize(40);

    //background
    if (!backText.loadFromFile(filename)) {

    }

    backGround.setTexture(backText);
    backGround.setPosition(0, 0);
    float scaleX = static_cast<float>(renderWin->getSize().x) / static_cast<float>(backText.getSize().x);
    float scaleY = static_cast<float>(renderWin->getSize().y) / static_cast<float>(backText.getSize().y);

    backGround.setScale(scaleX, scaleY);

    authors.setFont(font);
    authors.setString("Authors: Emanuele Nencioni, Gabriele Magrini");
    authors.setCharacterSize(20);
    authors.setPosition(renderWin->getView().getCenter().x - authors.getLocalBounds().width / 2,
                        renderWin->getSize().y + 20);
    authors.setOutlineThickness(2);
    authors.setFillColor(sf::Color(255, 255, 255, 175));


}

/***
 * function that draw all the button and background
 */
void MainMenu::render() {

    renderWin->draw(backGround);
    if (!nextLevel) {
        backText.loadFromFile("Sources/Pngs/main.png");
        startButton.render(*renderWin);
        optionButton.render(*renderWin);
        exitButton.render(*renderWin);
        float scaleX = static_cast<float>(renderWin->getView().getSize().x) / static_cast<float>(backText.getSize().x);
        float scaleY = static_cast<float>(renderWin->getView().getSize().y) / static_cast<float>(backText.getSize().y);
        backGround.setTexture(backText);
        backGround.setScale(scaleX, scaleY);
        backGround.setPosition(0, 0);

    } else {
        backText.loadFromFile("Sources/Pngs/loadin_screen.png");
        float scaleX = static_cast<float>(renderWin->getView().getSize().x) / static_cast<float>(backText.getSize().x);
        float scaleY = static_cast<float>(renderWin->getView().getSize().y) / static_cast<float>(backText.getSize().y);
        backGround.setTexture(backText);
        backGround.setScale(scaleX, scaleY);
        backGround.setPosition(0, 0);
    }
    renderWin->draw(authors);
    renderWin->display();
}

void MainMenu::update() {
    authors.setPosition(renderWin->getView().getCenter().x - authors.getLocalBounds().width / 2,
                        renderWin->getSize().y - 30);
    backGround.setTextureRect(sf::IntRect(0, 0, static_cast<int>(renderWin->getView().getSize().x),
                                          static_cast<int>(renderWin->getView().getSize().y)));
    auto mousePos = sf::Mouse::getPosition(*renderWin);
    auto worldPos = renderWin->mapPixelToCoords(mousePos);
    if (!nextLevel) {
        startButton.setPosition(renderWin->getView().getCenter().x - startButton.getShape().getSize().x / 2.0f, 375);
        startButton.update(worldPos);

        optionButton.setPosition(renderWin->getView().getCenter().x - optionButton.getShape().getSize().x / 2.0f, 480);
        optionButton.update(worldPos);

        exitButton.setPosition(renderWin->getView().getCenter().x - exitButton.getShape().getSize().x / 2.0f, 585);
        exitButton.update(worldPos);
    }

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

bool MainMenu::isNextLevel() {
    return nextLevel;
}

void MainMenu::setNextLevel(bool nextLevel) {
    MainMenu::nextLevel = nextLevel;
}
