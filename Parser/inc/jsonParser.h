#ifndef JSON_PARSER_H
#define JSON_PARSER_H

#include <iostream>
#include <fstream>
#include "IParser.h"
#include "IStream.h"
#include "IJsonReader.h"
#include "jsoncpp/json/json.h"

class JsonParser : public IParser
{
public:
    std::ifstream file;    
    IStream *streamFile;
    IJsonReader *jsonReader;
   Json::Value completeJsonData;

    JsonParser(IStream*,IJsonReader *);

    bool openFile();

    bool parseFile();

    void printFileData();

    void printJson(const Json::Value &, int);

    bool closeFile();

    ~JsonParser();
};

#endif