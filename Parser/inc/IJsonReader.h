#ifndef I_JSON_READER_H
#define I_JSON_READER_H

#include "jsoncpp/json.h"

class IJsonReader::public Json::Reader
{
public:
    IJsonReader();

    virtual bool parse(std::ifstream &, Json::Value &) = 0;

    ~IJsonReader();
};

#endif