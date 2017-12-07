//
//  Buffer.cpp
//  TestingCpp
//
//  Created by Charles McCrary on 12/6/17.
//  Copyright © 2017 Charles McCrary. All rights reserved.
//

#include "Buffer.hpp"


int Buffer::flush() {
    std::stringstream::str(std::string());
    std::stringstream::clear();
    return 0;
}
int Buffer::ignore() { // Throw away a word
    std::string s;
    (*this) >> s;
    return 0;
}