//
// Created by emanuele on 14/06/19.
//

#ifndef METALCFU_INVENTORY_H
#define METALCFU_INVENTORY_H

#include <memory>


using namespace std;

template <typename T>
class Inventory {

private:
    unique_ptr<T> buffer;
    int dim;
    int selectedItem;
};


#endif //METALCFU_INVENTORY_H
