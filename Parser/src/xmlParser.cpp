#include <iostream>
#include <fstream>
#include "xmlParser.h"
#include "pugixml-master/src/pugixml.hpp"

bool XmlParser::openFile()
{
    bool isOpen=false;
    file.open("../files/books.xml");
    if (!file.is_open())
        throw std::runtime_error("Unable to open file in XmlParser::openFile()");
        else isOpen=true;
    return isOpen;
}

bool XmlParser::parseFile()
{
    bool isParsed=false;
    xmlData = document.load(file);
    if (!xmlData)
        throw xmlData.description();
    else isParsed=true;
    return isParsed;
}

void XmlParser::printFileData()
{
    pugi::xml_node catalog = document.child("catalog");
    if (!catalog)
    {
        throw std::runtime_error("Root 'catalog' node not found in XmlParser::printFileData()");
    }
    std::cout << catalog.name() << std::endl;
    if (!catalog.first_child())
    {
        throw std::runtime_error("Node 'book' not found in XmlParser::printFileData()");
    }
    for (pugi::xml_node book = catalog.first_child(); book; book = book.next_sibling())
    {
        std::cout << book.name() << std::endl;
        pugi::xml_attribute id = book.first_attribute();
        printFile(id);
        for (pugi::xml_node element = book.first_child(); element; element = element.next_sibling())
        {
            printFile(element);
        }
    }
}

void XmlParser::printFile(pugi::xml_attribute &attribute)
{
    try
    {
        std::cout << attribute.name() << " = " << attribute.value() << std::endl;
    }
    catch (const std::exception &error)
    {
        std::cout << "Error: in XmlParser::printFile(pugi::xml_attribute &attribute) \n";
        throw std::exception(error);
    }
}

void XmlParser::printFile(pugi::xml_node &node)
{
    try
    {
        std::cout << node.name() << " = " << node.child_value() << std::endl;
    }
    catch (const std::exception &error)
    {
        std::cout << "Error: in XmlParser::printFile(pugi::xml_node &node) \n";
        throw std::exception(error);
    }
}

bool XmlParser::closeFile()
{
    bool isClose=false;
    file.close();
    if (file.is_open())
        throw std::runtime_error("Unable to close file in XmlParser::closeFile()");
    else isClose=true;
    return isClose;
}

XmlParser::~XmlParser()
{
    std::cout << "Destroyed XML object" << std::endl;
}