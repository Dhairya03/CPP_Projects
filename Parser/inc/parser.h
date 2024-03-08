#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>

class Parser
{
public:
    // virtual std::ifstream& getFile()=0;
    
    virtual void openFile()=0;

    virtual void parseFile()=0;

    virtual void printFileData()=0;

    virtual void closeFile()=0;

    void parse(Parser &fileParser);
};

#endif