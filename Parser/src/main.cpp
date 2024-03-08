#include <iostream>
#include <fstream>
#include <stdexcept>
#include "jsonParser.h"
#include "xmlParser.h"
#include "csvParser.h"

int main()
{
    Parser *p;

    int parserChoice;
    do
    {
        std::cout << "Enter parser number" << std::endl;
        std::cout << "1.JSON Parser" << std::endl;
        std::cout << "2.XML Parser" << std::endl;
        std::cout << "3.CSV Parser" << std::endl;
        std::cout << "4.Exit" << std::endl;

        std::cin >> parserChoice;
        switch (parserChoice)
        {
        case 1:
        {
            JsonParser jsonParser;
            // p=&jsonParser;
            p->parse(jsonParser);
            break;
        }
        case 2:
        {
            XmlParser xmlParser;
            // p=&xmlParser;
            p->parse(xmlParser);
            break;
        }
         case 3:
        {
            CsvParser csvParser;
            // p=&csvParser;
            p->parse(csvParser);
            break;
        }
        default:
            std::cout << "Exited Successfully" << std::endl;
            break;
        }
        
    } while (parserChoice != 4);
    return 0;
}


// g++ -I/home/dhairyagupta/training/c-_dhairyagupta/Parser/inc /home/dhairyagupta/training/c-_dhairyagupta/Parser/lib/pugixml-master/src/pugixml.cpp *.cpp -ljsoncpp