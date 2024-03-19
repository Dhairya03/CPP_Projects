#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <iostream>
#include <fstream>
#include "IParser.h"
#include "pugixml-master/src/pugixml.hpp"

class XmlParser : public IParser
{
private:
    std::ifstream file;
    pugi::xml_document document;
    pugi::xml_parse_result xmlData;

    bool openFile();

    bool parseFile();

    void printFileData();

    void printFile(pugi::xml_attribute &);

    void printFile(pugi::xml_node &);

    bool closeFile();

    ~XmlParser();
};

#endif