#include <iostream>
#include <fstream>
#include <stdexcept>
#include "parser.h"
#include "jsonParser.h"
#include "xmlParser.h"
#include "csvParser.h"
#include "inputValidator.h"

int main()
{
    try
    {
        Parser *parser;
        InputValidator inputValidator;

        do
        {
            try
            {
                std::cout << "Enter parser number" << std::endl;
                std::cout << "1.JSON Parser" << std::endl;
                std::cout << "2.XML Parser" << std::endl;
                std::cout << "3.CSV Parser" << std::endl;
                std::cout << "4.Exit" << std::endl;
                inputValidator.setParserChoice();

                switch (inputValidator.getParserChoice())
                {
                case 1:
                {
                    JsonParser jsonParser;
                    parser->parse(jsonParser);
                    break;
                }
                case 2:
                {
                    XmlParser xmlParser;
                    parser->parse(xmlParser);
                    break;
                }
                case 3:
                {
                    CsvParser csvParser;
                    parser->parse(csvParser);
                    break;
                }
                default:
                    std::cout << "Exited Successfully" << std::endl;
                    break;
                }
            }
            catch (const char *&error)
            {
                std::cout << "Error: "<<error << std::endl;
            }
            catch (const std::runtime_error &exception)
            {
                std::cout << "Error: " << exception.what() << std::endl;
            }
            catch (const std::exception &exception)
            {
                std::cout << "Error: " << exception.what() << std::endl;
            }

        } while (inputValidator.getParserChoice() != 4);
        return 0;
    }
    catch (const std::runtime_error &exception)
    {
        std::cout << "Error: " << exception.what() << std::endl;
    }
    catch (const std::exception &exception)
    {
        std::cout << "Error: " << exception.what() << std::endl;
    }
}

// g++ -I/home/dhairyagupta/training/c-_dhairyagupta/Parser/inc /home/dhairyagupta/training/c-_dhairyagupta/Parser/lib/pugixml-master/src/pugixml.cpp *.cpp -ljsoncpp