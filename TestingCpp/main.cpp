//
//  main.cpp
//  TestingCpp
//
//  Created by Charles McCrary on 11/23/17.
//  Copyright © 2017 Charles McCrary. All rights reserved.
//

#include <iostream>
#include "Parser.hpp"
#include <typeinfo>
#include <fstream>

#include "Buffer.hpp"

int main()
{
    std::cout << "Typescript Compiler 0.1 \n";
    Parser p;
    p.load("/Users/charlesmccrary/Desktop/in.txt","/Users/charlesmccrary/Desktop/out.txt");
    p.parse();
//    Buffer ss;
//    ss << "Hello";
//    std::cout << ss.str();
//    string test;
//    ss >> test;
//    std::cout << test;
//    ss.str("");
//    ss.clear();
//    ss << "Hello2";
//    std::cout << ss.str() << "End";

    std::cout << std::endl;
    return 0;
}

int writeFile()
{
    using namespace std;
    
    // ofstream is used for writing files
    // We'll make a file called Sample.dat
    ofstream outf("/Users/charlesmccrary/Desktop/test.txt");
    
    // If we couldn't open the output file stream for writing
    if (!outf)
    {
        // Print an error and exit
        cerr << "File could not be opened for writing!" << endl;
        exit(1);
    }
    
    // We'll write two lines into this file
    outf << "This is line 1" << endl;
    outf << "This is line 2" << endl;
    std::cout << "Done\n";
    
    return 0;
    
    // When outf goes out of scope, the ofstream
    // destructor will close the file
}
