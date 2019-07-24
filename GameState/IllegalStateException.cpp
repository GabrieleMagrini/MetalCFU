//
// Created by emanuele on 24/07/19.
//

#include "IllegalStateException.h"

IllegalStateException::IllegalStateException(std::string desc) : desc(std::move(desc)), exception() {}

std::string IllegalStateException::what() {
    return desc;
}
