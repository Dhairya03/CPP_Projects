#ifndef I_PARSER_H
#define I_PARSER_H

#include <iostream>
#include <fstream>

class IParser
{
public:
    virtual bool openFile() = 0;

    virtual bool parseFile() = 0;

    virtual void printFileData() = 0;

    virtual bool closeFile() = 0;

    virtual ~IParser();
};

#endif