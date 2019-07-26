//
// Created by emanuele on 26/07/19.
//

#include "MainMenu.h"

/***
 *
 * @param rw a pointer to a RenderWindow
 * @param filename name of the file for the background
 */
MainMenu::MainMenu(std::unique_ptr<sf::RenderWindow> rw, std::string filename, sf::Font font) : renderWin(
        std::move(rw)),
                                                                                                startButton(
                                                                                                        (*renderWin).getSize().x /
                                                                                                        2.0f - 200, 100,
                                                                                                        400, 100,
                                                                                                        font,
                                                                                                        "Start",
                                                                                                        "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/idleGreenButton.png",
                                                                                                        "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/hoverGreenButton.png",
                                                                                                        "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/pressedGreenButton.png"),

                                                                                                optionButton(
                                                                                                        (*renderWin).getSize().x /
                                                                                                        2.0f - 200, 210,
                                                                                                        400, 100,
                                                                                                        font,
                                                                                                        "Option",
                                                                                                        "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/idleGreenButton.png",
                                                                                                        "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/hoverGreenButton.png",
                                                                                                        "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/pressedGreenButton.png"),
                                                                                                exitButton
                                                                                                        ((*renderWin).getSize().x /
                                                                                                         2.0f - 200,
                                                                                                         320,
                                                                                                         400, 100, font,
                                                                                                         "Exit",
                                                                                                         "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/idleGreenButton.png",
                                                                                                         "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/hoverGreenButton.png",
                                                                                                         "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/pressedGreenButton.png") {
    sf::Texture text;
    if (!text.loadFromFile(filename))
        text.setSrgb(true);
    startButton.setCharacterSize(40);
    optionButton.setCharacterSize(40);
    exitButton.setCharacterSize(40);
    backGround.setTexture(text);
    backGround.setOrigin((*renderWin).getSize().x / 2.0f, (*renderWin).getSize().y / 2.0f);
    backGround.setScale(2.5, 2);

}

/***
 * function that draw all the button and background
 */
void MainMenu::render() {
    (*renderWin).draw(backGround);
    startButton.render(*renderWin);
    optionButton.render(*renderWin);
    exitButton.render(*renderWin);
}

void MainMenu::update() {
    auto mousePos = sf::Mouse::getPosition(*renderWin);
    auto worldPos = (*renderWin).mapPixelToCoords(mousePos);
    startButton.update(worldPos);
    optionButton.update(worldPos);
    exitButton.update(worldPos);

    (*renderWin).display();
}
