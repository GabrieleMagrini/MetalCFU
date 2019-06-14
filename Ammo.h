//
// Created by emanuele on 26/05/19.
//

#ifndef METALCFU_AMMO_H
#define METALCFU_AMMO_H


class Ammo {
public:

    explicit Ammo(int q=1): quantity(q){};
    Ammo(const Ammo& a) = default ;

    virtual ~Ammo()= default;

    int getQuantity() const;

    void setQuantity(int quantity);

private:
    int quantity;
};


#endif //METALCFU_AMMO_H
