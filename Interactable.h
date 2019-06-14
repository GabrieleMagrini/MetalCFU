//
// Created by emanuele on 03/06/19.
//

#ifndef METALCFU_INTERACTABLE_H
#define METALCFU_INTERACTABLE_H


class Interactable {
public:
    Interactable(int x,int y);
    virtual ~Interactable() = default;

    virtual void effect()=0;

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

private:

    int posX;
    int posY;
};


#endif //METALCFU_INTERACTABLE_H
