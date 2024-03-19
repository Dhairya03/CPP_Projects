#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <iostream>
#include <fstream>
#include "IParser.h"
#include "jsoncpp/json/json.h"

class JsonParser : public IParser
{
private:
    std::ifstream file;
    Json::Reader reader;
    Json::Value completeJsonData;

    bool openFile();

    bool parseFile();

    void printFileData();

    void printJson(const Json::Value &, int);

    bool closeFile();

    ~JsonParser();
};

#endif