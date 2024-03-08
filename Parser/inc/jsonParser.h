#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include<iostream>
#include<fstream>
#include"parser.h"
#include "jsoncpp/json/json.h"

class JsonParser : public Parser
{
private:
    std::ifstream file;
    Json::Reader reader;
    Json::Value completeJsonData;

public:
    std::ifstream &getFile();

    void openFile();

    void parseFile();

    void printFileData();

    void closeFile();
};

#endif