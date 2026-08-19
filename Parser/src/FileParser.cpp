#include "FileParser.h"
#include "IParser.h"

FileParser::FileParser(IParser *parser) : parser(parser) {}

bool FileParser::parse()
{
    bool isParsed = false;
    if (parser->openFile())
    {
        if (parser->parseFile())
        {
            parser->printFileData();
            isParsed = true;
        }
        parser->closeFile();
    }
    return isParsed;
}

FileParser::~FileParser() {}