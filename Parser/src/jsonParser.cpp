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
    std::cout << "Complete Json Data" << std::endl
              << completeJsonData << std::endl;
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