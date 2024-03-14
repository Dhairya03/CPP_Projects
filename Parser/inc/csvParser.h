#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <iostream>
#include <fstream>
#include "parser.h"
#include "../lib/rapidcsv.h"

class CsvParser : public Parser
{
private:
    std::ifstream file;
    std::vector<std::vector<std::string>> csvData;
    std::vector<std::string> csvDataColumnNames;

    bool openFile();

    bool parseFile();

    bool printFileData();

    bool closeFile();

    ~CsvParser();
};

#endif