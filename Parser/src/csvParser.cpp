#include <iostream>
#include <fstream>
#include "csvParser.h"
#include "rapidcsv.h"

bool CsvParser::openFile()
{
    file.open("../files/student_marks.csv");
    if (!file.is_open())
        throw std::runtime_error("Unable to open file in CsvParser::openFile()");
    return true;
}

bool CsvParser::parseFile()
{
    rapidcsv::Document document(file);
    if (!document.GetColumnCount())
    {
        throw std::runtime_error("Empty CSV file or unable to read columns in CsvParser::parseFile()");
    }

    try
    {
        csvDataColumnNames = document.GetColumnNames();
        for (int columnIndex = 0; columnIndex < document.GetColumnCount(); columnIndex++)
        {
            std::vector<std::string> columnData;
            for (int rowIndex = 0; rowIndex < document.GetRowCount(); rowIndex++)
            {
                columnData.push_back(document.GetCell<std::string>(columnIndex, rowIndex));
            }
            csvData.push_back(columnData);
        }
    }
    catch (const std::out_of_range &exception)
    {
        throw std::out_of_range(exception.what() + std::string(" in CsvParser::parseFile()"));
    }
    return true;
}

bool CsvParser::printFileData()
{
    try
    {
        for (int columnIndex = 0; columnIndex < csvData.size(); columnIndex++)
        {
            std::cout << csvDataColumnNames[columnIndex] << "\t";
            for (int rowIndex = 0; rowIndex < csvData[columnIndex].size(); rowIndex++)
            {
                std::cout << csvData[columnIndex][rowIndex] << "\t";
            }
            std::cout << std::endl;
        }
    }
    catch (const std::out_of_range &exception)
    {
        throw std::out_of_range(exception.what() + std::string(" in CsvParser::printFileData()"));
    }
    return true;
}

bool CsvParser::closeFile()
{
    file.close();
    if (file.is_open())
    {
        throw std::runtime_error("Unable to close file in CsvParser::closeFile()");
    }
    return true;
}

CsvParser::~CsvParser()
{
    std::cout << "Destroyed CSV object" << std::endl;
}