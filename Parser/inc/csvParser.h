#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <iostream>
#include <fstream>
#include "IParser.h"
#include "rapidcsv.h"
#include "IStream.h"

class CsvParser : public IParser
{
public:
    std::ifstream file;
    IStream *streamFile;
    std::vector<std::vector<std::string>> csvData;
    std::vector<std::string> csvDataColumnNames;

    CsvParser(IStream *);

    bool openFile();

    bool parseFile();

    void printFileData();

    bool closeFile();

    ~CsvParser();
};

#endif