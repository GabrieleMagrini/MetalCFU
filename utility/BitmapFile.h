//
// Created by emanuele on 01/08/19.
//

#ifndef METALCFU_BITMAPFILE_H
#define METALCFU_BITMAPFILE_H

#include <iostream>
#include <vector>
#include <memory>

class BitmapFile {

private:
    std::string filename;
    std::unique_ptr<FILE> file;
    std::vector<unsigned char> buffer;
};


#endif //METALCFU_BITMAPFILE_H
