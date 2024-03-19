#include <iostream>
#include <fstream>
#include "IStream.h"
#include "jsonParser.h"
#include "jsoncpp/json.h"

JsonParser::JsonParser(IStream*stream,IJsonReader*reader):streamFile(stream),jsonReader(reader){}

bool JsonParser::openFile()
{
    bool isOpen = false;
    streamFile->open("../files/quiz.json");
    if (!streamFile->is_open())
    {
        throw std::runtime_error("Unable to open file  or File not found in JsonParser::openFile()");
    }
    else
        isOpen = true;
    return isOpen;
}

bool JsonParser::parseFile()
{
    bool isParsed = false;
    if (!jsonReader->parse(*streamFile, completeJsonData))
    {
        throw std::runtime_error("Failed to parse complete JSON from file. Check if the file exists and is properly formatted in JsonParser::parseFile()");
    }
    else
        isParsed = true;
    return isParsed;
}

void JsonParser::printFileData()
{
    printJson(completeJsonData, 0);
}

void JsonParser::printJson(const Json::Value &value, int indent)
{
    try
    {
        if (value.isObject())
        {
            for (const auto &key : value.getMemberNames())
            {
                std::cout << std::endl
                          << std::string(indent, ' ') << key << ": ";
                printJson(value[key], indent + 2);
            }
        }
        else if (value.isArray())
        {
            std::cout << std::endl;
            for (int i = 0; i < value.size(); ++i)
            {
                std::cout << std::string(indent, ' ') << "- ";
                printJson(value[i], indent + 2);
            }
        }
        else
        {
            std::cout << value << std::endl;
        }
    }
    catch (const std::exception &error)
    {
        std::cout << "Error: in JsonParser::printFileData() \n";
        throw std::exception(error);
    }
}

bool JsonParser::closeFile()
{
    bool isClose = false;
    streamFile->close();
    if (streamFile->is_open())
    {
        throw std::runtime_error("Error: Unable to close file in JsonParser::closeFile()");
    }
    else
        isClose = true;
    return isClose;
}

JsonParser::~JsonParser()
{
    std::cout << "Destroyed JSON object" << std::endl;
}