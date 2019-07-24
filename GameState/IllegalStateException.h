//
// Created by emanuele on 24/07/19.
//

#ifndef METALCFU_ILLEGALSTATEEXCEPTION_H
#define METALCFU_ILLEGALSTATEEXCEPTION_H

#include <exception>
#include <string>

class IllegalStateException : public std::exception {
public:
    explicit IllegalStateException(std::string desc);

    std::string what();

private:
    std::string desc;
};


#endif //METALCFU_ILLEGALSTATEEXCEPTION_H
