//
// Created by emanuele on 23/05/19.
//
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Terrain.h"
#include "Factory/TerrainFactory.h"
#include <fstream>
#include <memory>

#include "GUI/OptionMenu.h"
#include "GUI/MainMenu.h"
#include "Game.h"

int main() {

    std::shared_ptr<RenderWindow> rw(new sf::RenderWindow(sf::VideoMode(1280, 720), "Metal CFU", sf::Style::Close));
    rw->setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().width / 2 - rw->getSize().x / 2, 0));
    sf::Font font;
    font.loadFromFile("Sources/Raleway-Medium.ttf");
    Game g(rw, font);
    g.loop();

    return 0;
}