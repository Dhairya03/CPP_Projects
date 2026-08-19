#ifndef JSON_READER_H
#define JSON_READER_H

#include "IJsonReader.h"
#include "../lib/jsoncpp/json.h"

class JsonReader:public IJsonReader{
    public:
    Json::Reader reader;

    JsonReader(Json::Reader&);

    bool parse(std::ifstream&,Json::Value&);

    ~JsonReader();
};

#endif