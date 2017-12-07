//
//  Parser.cpp
//  TestingCpp
//
//  Created by Charles McCrary on 12/3/17.
//  Copyright © 2017 Charles McCrary. All rights reserved.
//

#include "Parser.hpp"

Parser::Parser() {
    
}
int Parser::load(string inputPath, string outputPath) {
    
    // Create read stream
    input.open(inputPath);
    if (!input) {
        cerr << inputPath + " could not be opened for reading!" << endl;
        return 1;
    }
    // Create write stream
    output.open(outputPath);
    if (!output) {
        cerr << outputPath + " could not be opened for writing!" << endl;
        return 1;
    }
    return 0;
}
int Parser::parse() {
    while (input)
    {
        string thisLine;
        getline(input, thisLine);
        cout << "Adding line: " << thisLine << endl;
        parseLine(thisLine);
        // output << parsedLine << endl;
    }
    return 0;
}


void Parser::parseLine(string line) {
    
    
    for (int i=0;i < line.length(); i++) {
        if (line[i] == ';') {
            cout << "Parsing statement: " << buffer.str();
            cout << endl;
            parseStatement();
        } else { // ; are not included
            buffer << line[i];
        }
    }
    
}

int Parser::parseStatement() {
    
    while(buffer.peek() != EOF) {
        string initator;
        buffer >> initator;
        cout << "INIT FC " << initator << endl;
        if (initator == "\n" || initator == "") continue;
        
        cout << "Dispatching initator " << initator << endl;
        
        dispatch(initator);
        
    }
    output << ';' << endl;
    cout << "Statement complete" << endl;
    buffer.flush();
    
    return 0;
}

int Parser::dispatch(string initator) {
    if (initator == "let") {
        // declare
        declare();
    } else if (initator == "const") {
        declareConst();
    }
    
    return 0;
}

int Parser::declare () {
    string name = getDeclaritiveName();
    string type = getType();
    cout << "Declaring " << type << " " << name << endl;
    output << type << " " << name;
    string next;
    buffer >> next;
    if (next == "=") {
        string value;
        buffer >> value;
        output << " = " << value;
    }
    return 0;
}
int Parser::declareConst () {
    string name = getDeclaritiveName();
    string type = getType();
    cout << "Declaring const " << type << " " << name << endl;
    output << "const " << type << " " << name;
    string next;
    buffer >> next;
    if (next == "=") {
        string value;
        buffer >> value;
        output << " = " << value;
    }
    return 0;
}

string Parser::getDeclaritiveName() {
    string item;
    buffer >> item;
    string name = "";
    for (int i=0;i < item.length(); i++) {
        if (item[i] != ':') {
            name += item[i];
        } else {
            break;
        }
    }
    return name;
}

string Parser::getType(){
    string jsType;
    buffer >> jsType;
    if (jsType == "number") {
        return "double";
    } else if (jsType == "string") {
        // Add include of string lib if not alreay
        return "string";
    } else if (jsType == "boolean") {
        return "bool";
    }
    return "UNSUPPORTED TYPE";
}

int Parser::assign(string name) {
    return 0;
}



