//
// Created by emanuele on 26/08/19.
//

#include "GameOverMenu.h"

GameOverMenu::GameOverMenu(std::shared_ptr<sf::RenderWindow> rw, const std::string &filename, const sf::Font &font)
        : renderWin(std::move(rw)),
          exitGame(renderWin->getView().getCenter().x - mainMenu.getShape().getLocalBounds().width - 5, 300, 400, 100,
                   font, "Exit Game",
                   " GUI/texture/idleGreenButton.png", " GUI/texture/hoverGreenButton.png",
                   "GUI/texture/pressedGreenButton.png"),
          mainMenu(renderWin->getSize().x / 2.0f + 200, 300, 400, 100, font, "Main Menu",
                   " GUI/texture/idleGreenButton.png", " GUI/texture/hoverGreenButton.png",
                   "GUI/texture/pressedGreenButton.png"), win(false) {
    if (!bgTexure.loadFromFile(filename))
        std::cerr << "error while open file : " << filename << std::endl;
    backGround.setPosition(0, 0);
    backGround.setTexture(bgTexure);
    float scaleX = static_cast<float>(renderWin->getSize().x) / static_cast<float>(bgTexure.getSize().x);
    float scaleY = static_cast<float>(renderWin->getSize().y) / static_cast<float>(bgTexure.getSize().y);

    backGround.setScale(scaleX, scaleY);

    text.setFont(font);
    text.setFillColor(sf::Color::Red);
    text.setCharacterSize(40);
}

const sf::Texture &GameOverMenu::getBgTexure() const {
    return bgTexure;
}

void GameOverMenu::setBgTexure(const sf::Texture &bgTexure) {
    GameOverMenu::bgTexure = bgTexure;
}

const sf::Text &GameOverMenu::getText() const {
    return text;
}

void GameOverMenu::setText(const sf::Text &text) {
    GameOverMenu::text = text;
}

bool GameOverMenu::isWin() const {
    return win;
}

void GameOverMenu::setWin(bool win) {
    GameOverMenu::win = win;
}

void GameOverMenu::update() {
    if (win) {
        text.setString("Congrats! You Win!");
    } else {
        text.setString("Game Over... You Lose");
    }
    text.setPosition(renderWin->getView().getCenter().x - text.getLocalBounds().width / 2.0f, 100);
    auto mousePos = sf::Mouse::getPosition(*renderWin);
    auto worldPos = renderWin->mapPixelToCoords(mousePos);
    mainMenu.setPosition(renderWin->getView().getCenter().x - mainMenu.getShape().getLocalBounds().width - 5, 300);
    mainMenu.update(worldPos);
    exitGame.setPosition(renderWin->getView().getCenter().x + exitGame.getShape().getLocalBounds().width + 5, 300);
    exitGame.update(worldPos);
}

void GameOverMenu::render() {
    renderWin->draw(backGround);
    renderWin->draw(text);

    mainMenu.render(*renderWin);
    exitGame.render(*renderWin);
}
