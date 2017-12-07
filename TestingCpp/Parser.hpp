//
//  Parser.hpp
//  TestingCpp
//
//  Created by Charles McCrary on 12/3/17.
//  Copyright © 2017 Charles McCrary. All rights reserved.
//

#ifndef Parser_hpp
#define Parser_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <typeinfo>
#include <fstream>
#include <cstdlib>

#include "Buffer.hpp"

using namespace std;

class Parser
{
public:
    Parser();
    int parse();
    int load(string inputPath, string outputPath);


private:
    ifstream input;
    ofstream output;
    Buffer buffer;
    
    void parseLine(string line);
    int parseStatement();
    int dispatch(string initator);
    int declare();
    int declareConst();
    string getDeclaritiveName();
    string getType();
    int assign(string name);

};

#endif /* Parser_hpp */
