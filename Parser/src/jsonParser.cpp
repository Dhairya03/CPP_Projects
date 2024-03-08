#include <iostream>
#include <fstream>
#include "jsonParser.h"

std::ifstream &JsonParser::getFile()
{
    return file;
}

void JsonParser::openFile()
{
    file.open("../files/example_2.json");
    if (file.is_open())
        std::cout << "open" << std::endl;
    else
        std::cout << "close" << std::endl;
}

void JsonParser::parseFile()
{
    reader.parse(file, completeJsonData);
    if (file.is_open())
        std::cout << "open" << std::endl;
    else
        std::cout << "close" << std::endl;
    std::cout << "Complete Json Data" << std::endl
              << completeJsonData << std::endl;
}

void JsonParser::printFileData()
{
    if (file.is_open())
        std::cout << "open" << std::endl;
    else
        std::cout << "close" << std::endl;
    std::cout << "Complete Json Data" << std::endl
              << completeJsonData << std::endl;
    // std::cout << "math:" << completeJsonData["quiz"]["maths"]["q2"] << std::endl;
}

void JsonParser::closeFile()
{
    if (file.is_open())
        std::cout << "open" << std::endl;
    else
        std::cout << "close" << std::endl;

    file.close();
    if (file.is_open())
        std::cout << "open" << std::endl;
    else
        std::cout << "close" << std::endl;
}