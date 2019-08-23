//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAMESTATE_H
#define METALCFU_GAMESTATE_H


#include "IllegalStateException.h"

class Game;

class GameState {
public:
    explicit GameState(std::string sn);

    virtual ~GameState() = default;

    virtual void gameOverState(Game &g);

    virtual void exitGameState(Game &g);

    virtual void mainMenuState(Game &g);

    virtual void optionMenuState(Game &g);

    virtual void startGameState(Game &g);

    virtual void pauseGameState(Game &g);

    const std::string &getStateName() const;

    void setStateName(const std::string &stateName);

private:
    std::string stateName;
};


#endif //METALCFU_GAMESTATE_H
