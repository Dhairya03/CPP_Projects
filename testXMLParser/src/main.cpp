#include <iostream>
#include <fstream>
#include "../lib/pugixml-master/src/pugixml.hpp"

int main()
{
    pugi::xml_document doc;
    pugi::xml_parse_result result = doc.load_file("../xmlFile/books.xml");
    if (!result)
        return -1;
    // showcases error msg
    std::cout << result.description() << std::endl;
    pugi::xml_node catalog = doc.child("catalog");
    std::cout << catalog.name() << std::endl;
    for (pugi::xml_node book = catalog.first_child(); book; book = book.next_sibling())
    {
        std::cout << book.name() << std::endl;
        pugi::xml_attribute id = book.first_attribute();
        std::cout << id.name() << " = " << id.value() << std::endl;
        for(pugi::xml_node element =book.first_child();element;element=element.next_sibling()){
            std::cout<<element.name()<<" = "<<element.child_value()<<std::endl;
        }
    }
}


// g++ -I/home/dhairyagupta/training/c-_dhairyagupta/testXMLParser/lib /home/dhairyagupta/training/c-_dhairyagupta/testXMLParser/lib/pugixml-master/src/pugixml.cpp main.cpp