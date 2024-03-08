#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <iostream>
#include <fstream>
#include "parser.h"

class CsvParser : public Parser
{
private:
    std::ifstream file;

public:
    std::ifstream &getFile();

    void openFile();

    void parseFile();

    void printFileData();

    void closeFile();
};

#endif