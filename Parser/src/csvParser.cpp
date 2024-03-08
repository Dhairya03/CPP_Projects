#include <iostream>
#include <fstream>
#include "csvParser.h"
#include "../lib/rapidcsv.h"

bool CsvParser::openFile()
{
    file.open("../files/student_marks.csv");
    if (!file.is_open())
        throw std::runtime_error("Unable to open file");
    return true;
}

bool CsvParser::parseFile()
{
    rapidcsv::Document document(file);
    if (!document.GetColumnCount())
    {
        throw std::runtime_error("Empty CSV file or unable to read columns.");
    }

    try
    {
        csvDataColumnNames = document.GetColumnNames();
        for (int index = 0; index < document.GetColumnCount(); index++)
        {
            std::vector<std::string> columnData;
            for (int rowIndex = 0; rowIndex < document.GetRowCount(); rowIndex++)
            {
                columnData.push_back(document.GetCell<std::string>(index, rowIndex));
            }
            csvData.push_back(columnData);
        }
    }
    catch (const std::out_of_range &exception)
    {
        throw std::out_of_range(exception.what() + std::string(" in CSV Parser"));
    }
    return true;
}

bool CsvParser::printFileData()
{
    try
    {
        for (int index = 0; index < csvData.size(); index++)
        {
            std::cout << csvDataColumnNames[index] << "\t";
            for (int rowIndex = 0; rowIndex < csvData[index].size(); rowIndex++)
            {
                std::cout << csvData[index][rowIndex] << "\t";
            }
            std::cout << std::endl;
        }
    }
    catch (const std::out_of_range &exception)
    {
        throw std::out_of_range(exception.what() + std::string(" in CSV Parser"));
    }
    return true;
}

bool CsvParser::closeFile()
{
    file.close();
    if (file.is_open())
    {
        throw std::runtime_error("Unable to close file");
    }
    return true;
}