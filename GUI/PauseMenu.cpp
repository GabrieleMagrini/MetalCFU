//
// Created by emanuele on 31/07/19.
//

#include "PauseMenu.h"

PauseMenu::PauseMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &imageFileName, const sf::Font &font)
        : renderWin(std::move(rw)), backGameButton((*renderWin).getSize().x / 2.0f - 200, 100,
                                                   400, 100,
                                                   font,
                                                   "Back to Game",
                                                   "GUI/texture/idleGreenButton.png",
                                                   "GUI/texture/hoverGreenButton.png",
                                                   "GUI/texture/pressedGreenButton.png"),

          mainMenuButton((*renderWin).getSize().x / 2.0f - 200, 100,
                         400, 100,
                         font,
                         "Start",
                         "GUI/texture/idleGreenButton.png",
                         "GUI/texture/hoverGreenButton.png",
                         "GUI/texture/pressedGreenButton.png") {


}
