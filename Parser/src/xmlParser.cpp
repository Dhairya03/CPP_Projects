#include <iostream>
#include <fstream>
#include "xmlParser.h"
#include "../lib/pugixml-master/src/pugixml.hpp"

// pugi::xml_document &XmlParser::getDocument()
// {
//     return document;
// }

// std::ifstream& XmlParser::getFile(){
//     return file;
// }

void XmlParser::openFile()
{
    file.open("../files/books.xml");
    result = document.load(file);
}

void XmlParser::parseFile()
{
    pugi::xml_node catalog = document.child("catalog");
    std::cout << catalog.name() << std::endl;
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

void XmlParser::printFileData(){
    std::cout<<"Printed Successfully"<<std::endl;
}

void XmlParser::printFile(pugi::xml_attribute &attribute)
{
    std::cout << attribute.name() << " = " << attribute.value() << std::endl;
}
void XmlParser::printFile(pugi::xml_node &node)
{
    std::cout << node.name() << " = " << node.child_value() << std::endl;
}

void XmlParser::closeFile(){
    file.close();
}