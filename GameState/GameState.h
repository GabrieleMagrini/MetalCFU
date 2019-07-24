//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_GAMESTATE_H
#define METALCFU_GAMESTATE_H


class GameState {
public:
    GameState() = default;

    virtual ~GameState() = default;

    virtual void gameOverState();

    virtual void exitGameState();
    virtual void mainMenuState();

    virtual void OptionState();

    virtual void startGameState();

    virtual void pauseGameState();

};


#endif //METALCFU_GAMESTATE_H
