#include "JsonReader.h"
#include "jsoncpp/json.h"

JsonReader::JsonReader(Json::Reader &reader) : reader(reader) {}

bool JsonReader::parse(std::ifstream &file, Json::Value &root)
{
    return reader.parse(file, root);
}

JsonReader::~JsonReader() {}