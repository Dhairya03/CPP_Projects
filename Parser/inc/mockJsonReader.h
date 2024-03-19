#ifndef MOCK_JSON_READER_H
#define MOCK_JSON_READER_H

#include "IJsonReader.h"
#include "fstream"
#include "jsoncpp/json.h"
#include <gmock/gmock.h>

class MockJsonReader:public IJsonReader{
    public:
    MOCK_METHOD(bool,parse,(std::ifstream&, Json::Value &));
};
#endif