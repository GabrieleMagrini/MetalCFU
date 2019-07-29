//
// Created by emanuele on 23/05/19.
//
#include <iostream>
#include "Player.h"
#include "Map.h"
#include "Terrain.h"
#include "Factory/TerrainFactory.h"
#include <fstream>

int main() {

    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML works!");

    int x = static_cast<double>(window.getSize().x / 2.); //size
    int y = window.getSize().y / 2.;

    sf::View view(sf::Vector2f(x, y), sf::Vector2f(1280.0f, 720.0f));
    view.setCenter(600, 300);

    sf::Texture wallpaper;
    wallpaper.loadFromFile(
            "/home/madmag/Desktop/UniFi/Programmazione/Progetto/Sources/Pngs/wallpaper_1.jpeg");
    sf::Sprite lol;
    sf::Vector2u size = wallpaper.getSize();
    lol.setTexture(wallpaper);
    lol.setOrigin(size.x / 10, size.y / 10);
    lol.setScale(2.5, 2);

    window.setKeyRepeatEnabled(false);
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(30);

    window.setView(view);

    Map a;
    std::vector<Terrain> sprites = a.createMap(std::ifstream(
            "/home/madmag/Desktop/UniFi/Programmazione/Progetto/Sources/Maps/mappa.txt"));

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();


        }
        window.draw(lol);
        for (auto &sprite : sprites) {
            sprite.setOrigin(100, -310);
            window.draw(sprite);

        }
        window.display();
    }
    return 0;
}