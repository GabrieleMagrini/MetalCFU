//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAMESTATE_H
#define METALCFU_GAMESTATE_H


#include "IllegalStateException.h"

class GameState {
public:
    explicit GameState(std::string sn);

    virtual ~GameState() = default;

    virtual void gameOverState();

    virtual void exitGameState();

    virtual void mainMenuState();

    virtual void optionMenuState();

    virtual void startGameState();

    virtual void pauseGameState();

    const std::string &getStateName() const;

     void setStateName(const std::string &stateName);

private:
    std::string stateName;
};


#endif //METALCFU_GAMESTATE_H
