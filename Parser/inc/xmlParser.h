#ifndef XML_PARSER_H
#define XML_PARSER_H

#include <iostream>
#include <fstream>
#include "parser.h"
#include "../lib/pugixml-master/src/pugixml.hpp"

class XmlParser : public Parser
{
private:
    std::ifstream file;
    pugi::xml_document document;
    pugi::xml_parse_result result;

public:
    pugi::xml_document &getDocument();

    std::ifstream &getFile();

    void openFile();

    void parseFile();

    void printFileData();

    void printFile(pugi::xml_attribute &attribute);

    void printFile(pugi::xml_node &node);

    void closeFile();
};

#endif