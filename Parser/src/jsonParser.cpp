#include <iostream>
#include <fstream>
#include "jsonParser.h"
#include <stdexcept>

// std::ifstream &JsonParser::getFile()
// {
//     return file;
// }

void JsonParser::openFile()
{
    file.open("../files/example_2.json");
    if (!file.is_open())
    {
        std::cerr << "Error: Unable to open file." << std::endl;
    }
}

void JsonParser::parseFile()
{
    try
    {
        if (!reader.parse(file, completeJsonData))
        {
            throw std::runtime_error("Failed to parse JSON from file. Check if the file exists and is properly formatted.");
        }
        std::cout << "Success" << std::endl;
    }
    catch (const std::exception &exception)
    {
        std::cerr << "Error: " << exception.what() << std::endl;
    }
}

void JsonParser::printFileData()
{
    std::cout << "Complete Json Data" << std::endl
              << completeJsonData << std::endl;
    // std::cout << "math:" << completeJsonData["quiz"]["maths"]["q2"] << std::endl;
}

void JsonParser::closeFile()
{
    file.close();
    if (file.is_open())
    {
        std::cerr << "Error: Unable to close file." << std::endl;
    }
}