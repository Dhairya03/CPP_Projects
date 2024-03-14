#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <iostream>
#include <fstream>
#include "parser.h"
#include "jsoncpp/json/json.h"

class JsonParser : public Parser
{
private:
    std::ifstream file;
    Json::Reader reader;
    Json::Value completeJsonData;

    bool openFile();

    bool parseFile();

    bool printFileData();

    bool printJson(const Json::Value &, int);

    bool closeFile();

    ~JsonParser();
};

#endif