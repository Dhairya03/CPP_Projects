#include <iostream>
#include <fstream>
#include "xmlParser.h"
#include "../lib/pugixml-master/src/pugixml.hpp"

bool XmlParser::openFile()
{
    file.open("../files/books.xml");
    if (!file.is_open())
        throw std::runtime_error("Unable to open file");
    return true;
}

bool XmlParser::parseFile()
{

    result = document.load(file);
    if (!result)
        throw result.description();

    return true;
}

bool XmlParser::printFileData()
{
    pugi::xml_node catalog = document.child("catalog");
    if (!catalog)
    {
        throw std::runtime_error("Root 'catalog' node not found.");
    }
    std::cout << catalog.name() << std::endl;
    if (!catalog.first_child())
    {
        throw std::runtime_error("Node 'book' not found.");
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
    return true;
}

bool XmlParser::printFile(pugi::xml_attribute &attribute)
{
    std::cout << attribute.name() << " = " << attribute.value() << std::endl;
    return true;
}

bool XmlParser::printFile(pugi::xml_node &node)
{
    std::cout << node.name() << " = " << node.child_value() << std::endl;
    return true;
}

bool XmlParser::closeFile()
{
    file.close();
    if (file.is_open())
        throw std::runtime_error("Unable to close file");

    return true;
}