//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_AMMO_H
#define METALCFU_AMMO_H

#include <SFML/Graphics.hpp>

class GameCharacter;

class Terrain;


class Ammo : public sf::Sprite {
public:

    explicit Ammo(bool c = false, bool s = false) : terrainCollision(c), isShot(s),
                                                    gamecharacterCollision(c) {
        auto ammo = new sf::Texture();
        ammo->loadFromFile(
                "Sources/Pngs/weapon textures/ammo.png");
        this->setTexture(*ammo);
    };

    Ammo(const Ammo &a) = default;


    virtual ~Ammo() = default;

    void setTerrainCollision(bool v);

    bool getTerrainCollision() const;

    void shoot(sf::Vector2f posRif, sf::Vector2f posFin);

    bool isIsShot() const;

    void setIsShot(bool isShot);

    bool checkCollision(std::vector<GameCharacter> e, std::vector<Terrain> t);

    bool isGamecharacterCollision() const;

    void setGamecharacterCollision(bool gamecharacterCollision);

private:

    bool terrainCollision;
    bool isShot;
    bool gamecharacterCollision;
};


#endif //METALCFU_AMMO_H
