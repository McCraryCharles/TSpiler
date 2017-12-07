//
//  Buffer.hpp
//  TestingCpp
//
//  Created by Charles McCrary on 12/6/17.
//  Copyright © 2017 Charles McCrary. All rights reserved.
//

#ifndef Buffer_hpp
#define Buffer_hpp

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

class Buffer: public std::stringstream {
    
private:
    
    
public:
    int flush();
    int ignore();
//    friend std::istream &operator>>( std::istream  &input, Buffer &buffer );
};

#endif /* Buffer_hpp */
