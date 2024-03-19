#include <iostream>
#include <fstream>
#include <stdexcept>
#include "IParser.h"
#include "FileParser.h"
#include "jsonParser.h"
#include "xmlParser.h"
#include "csvParser.h"
#include "inputValidator.h"

bool handleParser(InputValidator &inputValidator)
{
    IParser *parser = nullptr;
    bool isValidParse = true;
    switch (inputValidator.getParserChoice())
    {
    case 1:
    {
        parser = new JsonParser;
        break;
    }
    case 2:
    {
        parser = new XmlParser;
        break;
    }
    case 3:
    {
        parser = new CsvParser;
        break;
    }
    default:
        isValidParse = false;
        std::cout << "Exited Successfully" << std::endl;
        break;
    }
    FileParser fileParser(parser);
    if (isValidParse)
    {
        FileParser.parse();
    }
    delete parser;
    return isValidParse;
}

int main()
{
    try
    {
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
                handleParser(inputValidator);
            }
            catch (const char *error)
            {
                std::cout << "Error: " << error << std::endl;
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
    catch (const std::exception &exception)
    {
        std::cout << "Error: " << exception.what() << std::endl;
    }
}
