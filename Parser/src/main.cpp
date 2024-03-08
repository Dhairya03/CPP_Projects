#include <iostream>
#include <fstream>
#include "jsonParser.h"
#include "xmlParser.h"
#include "csvParser.h"

int main()
{
    // Parser *p;
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
            //p=&jsonParser;
            jsonParser.openFile();
            jsonParser.parseFile();
            jsonParser.printFileData();
            jsonParser.closeFile();
            break;
        }
        case 2:
        {
            XmlParser xmlParser;
            // p=&xmlParser;
            xmlParser.openFile();
            xmlParser.parseFile();
            xmlParser.printFileData();
            xmlParser.closeFile();
            break;
        }
         case 3:
        {
            CsvParser csvParser;
            //p=&csvParser;
            csvParser.openFile();
            csvParser.parseFile();
            csvParser.printFileData();
            csvParser.closeFile();
            break;
        }
        default:
            std::cout << "Exited Successfully" << std::endl;
            break;
        }
        //p->parse();
    } while (parserChoice != 4);
    return 0;
}


// g++ -I/home/dhairyagupta/training/c-_dhairyagupta/Parser/inc /home/dhairyagupta/training/c-_dhairyagupta/Parser/lib/pugixml-master/src/pugixml.cpp *.cpp -ljsoncpp