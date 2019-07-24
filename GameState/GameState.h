//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAMESTATE_H
#define METALCFU_GAMESTATE_H


class GameState {
public:
    GameState() = default;

    virtual ~GameState() = default;

    virtual void gameOverState() = 0;

    virtual void exitGameState() = 0;

    virtual void mainMenuState() = 0;

    virtual void OptionState() = 0;

    virtual void startGameState() = 0;

    virtual void pauseGameState() = 0;

};


#endif //METALCFU_GAMESTATE_H
