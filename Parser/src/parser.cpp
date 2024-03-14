#include "parser.h"

bool Parser::parse(Parser &fileParser)
{
    fileParser.openFile();
    fileParser.parseFile();
    fileParser.printFileData();
    fileParser.closeFile();
    return true;
}

bool Parser::parse()
{
    openFile();
    parseFile();
    printFileData();
    closeFile();
    return true;
}

Parser::~Parser()
{
    std::cout<<"Destroyed Parser object"<<std::endl;
}