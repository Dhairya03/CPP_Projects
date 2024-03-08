#include <iostream>
#include <fstream>
#include "jsonParser.h"
#include <stdexcept>

bool JsonParser::openFile()
{
    file.open("../files/example_2.json", std::ifstream::binary);
    if (!file.is_open())
    {
        throw std::runtime_error("Unable to open file.");
    }
    return true;
}

bool JsonParser::parseFile()
{
    if (!reader.parse(file, completeJsonData))
    {
        throw std::runtime_error("Failed to parse complete JSON from file. Check if the file exists and is properly formatted.");
    }
    return true;
}

bool JsonParser::printFileData()
{
    printJson(completeJsonData, 0);
    return true;
}

bool JsonParser::printJson(const Json::Value &value, int indent)
{
    if (value.isObject())
    {
        for (const auto &key : value.getMemberNames())
        {
            std::cout<<std::endl << std::string(indent, ' ') << key << ": ";
            printJson(value[key], indent+2);
        }
    }
    else if (value.isArray())
    {
        std::cout<<std::endl;
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
    return true;
}

bool JsonParser::closeFile()
{
    file.close();
    if (file.is_open())
    {
        throw std::runtime_error("Error: Unable to close file.");
    }
    return true;
}