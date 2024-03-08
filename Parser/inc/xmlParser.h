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
    pugi::xml_parse_result xmlData;

    bool openFile();

    bool parseFile();

    bool printFileData();

    bool printFile(pugi::xml_attribute &);

    bool printFile(pugi::xml_node &);

    bool closeFile();
};

#endif