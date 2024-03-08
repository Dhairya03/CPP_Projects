#include <iostream>
#include <fstream>
#include "csvParser.h"
#include "../lib/rapidcsv.h"

std::ifstream &CsvParser::getFile()
{
    return file;
}

void CsvParser::openFile()
{
    file.open("../files/student_marks.csv");
    if (!file.is_open())
        std::cout << "Open the file" << std::endl;
    else
        std::cout << "file is openened" << std::endl;
}

void CsvParser::parseFile()
{
   // rapidcsv::Document document(file);
}

void CsvParser::printFileData()
{
    if (!file.is_open())
        std::cout << "Open the file" << std::endl;
    rapidcsv::Document document(file);
    for(int index=0;index<document.GetColumnCount();index++){
        std::cout<<document.GetColumnName(index)<<" ";
        for(int rowIndex=0;rowIndex<document.GetRowCount();rowIndex++){
            std::cout<<document.GetCell<std::string>(index,rowIndex)<<"   ";
        }
        std::cout<<std::endl;
    }
}

void CsvParser::closeFile()
{

    file.close();
    std::cout<<"File is closed"<<std::endl;
}