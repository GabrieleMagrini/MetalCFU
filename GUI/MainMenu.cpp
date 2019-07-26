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
                                                                                                startButton(50, 100,
                                                                                                            200, 50,
                                                                                                            font,
                                                                                                            "Start",
                                                                                                            "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/idleGreenButton.png",
                                                                                                            "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/hoverGreenButton.png",
                                                                                                            "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/pressedGreenButton.png"),

                                                                                                optionButton(50, 100,
                                                                                                             200, 50,
                                                                                                             font,
                                                                                                             "Start",
                                                                                                             "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/idleGreenButton.png",
                                                                                                             "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/hoverGreenButton.png",
                                                                                                             "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/pressedGreenButton.png"),
                                                                                                exitButton
                                                                                                        (50, 100, 200,
                                                                                                         50, font,
                                                                                                         "Start",
                                                                                                         "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/idleGreenButton.png",
                                                                                                         "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/hoverGreenButton.png",
                                                                                                         "/run/media/emanuele/Volume/Dati/Università/Progetto Programmazione/MetalCFU/GUI/texture/pressedGreenButton.png") {
    sf::Texture text;
    if (!text.loadFromFile(filename))
        text.setSrgb(true);

    backGround.setTexture(text);


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
    auto mousePos = sf::Mouse::getPosition();
    auto worldPos = (*renderWin).mapPixelToCoords(mousePos);
    startButton.update(worldPos);
    optionButton.update(worldPos);
    exitButton.update(worldPos);
}
