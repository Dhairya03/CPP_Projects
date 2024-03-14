#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <fstream>

class Parser
{
private:
    virtual bool openFile() = 0;

    virtual bool parseFile() = 0;

    virtual bool printFileData() = 0;

    virtual bool closeFile() = 0;

public:
    bool parse(Parser &fileParser);

    bool parse();

    virtual ~Parser();
};

#endif