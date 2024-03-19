#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <iostream>
#include <fstream>
#include "parser.h"
#include "rapidcsv.h"

class CsvParser : public IParser
{
private:
    std::ifstream file;
    std::vector<std::vector<std::string>> csvData;
    std::vector<std::string> csvDataColumnNames;

    bool openFile();

    bool parseFile();

    void printFileData();

    bool closeFile();

    ~CsvParser();
};

#endif