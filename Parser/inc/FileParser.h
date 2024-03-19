#ifndef FILE_PARSER_H
#define FILE_PARSER_H

#include "IParser.h"

class FileParser
{
    IParser *parser;

public:
    FileParser(IParser *);
    bool parse();
    ~FileParser();
};

#endif