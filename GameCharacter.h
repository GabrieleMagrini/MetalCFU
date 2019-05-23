//
// Created by emanuele on 23/05/19.
//

#ifndef METALCFUREPO_GAMECHARACTER_H
#define METALCFUREPO_GAMECHARACTER_H


class GameCharacter {
public:
    GameCharacter();

    ~GameCharacter();

private:
    int HP;
    int posX;
public:
    int getHp() const;

    void setHp(int hp);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    int getStrenght() const;

    void setStrenght(int strenght);

    int getMovementSpeed() const;

    void setMovementSpeed(int movementSpeed);

private:
    int posY;
    int strenght;

    int movementSpeed;

};


#endif //METALCFUREPO_GAMECHARACTER_H
