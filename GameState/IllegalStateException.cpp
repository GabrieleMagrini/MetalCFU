//
// Created by emanuele on 24/07/19.
//

#include "IllegalStateException.h"

IllegalStateException::IllegalStateException(std::string &desc) : desc(desc), exception() {

}

std::string IllegalStateException::what() {
    return desc;
}
