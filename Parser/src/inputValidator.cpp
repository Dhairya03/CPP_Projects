#include <iostream>
#include <limits>
#include "inputValidator.h"

int InputValidator::getParserChoice()
{
    return parserChoice;
}

bool InputValidator::setParserChoice()
{
    while (true)
    {
        try
        {
            std::cin >> parserChoice;
            if (isValidInput() && isValidParserChoice())
                break;
        }
        catch (const std::invalid_argument &error)
        {
            std::cout << "Error:" << error.what() << std::endl;
        }
        catch (const std::runtime_error &error)
        {
            std::cout << "Error:" << error.what() << std::endl;
        }
        catch (const std::exception &exception)
        {
            std::cout << "Error: " << exception.what() << std::endl;
        }
    }
    return true;
}

bool InputValidator::isValidParserChoice()
{
    bool isvalidChoice=false;
    if (parserChoice < 1 || parserChoice > 4)
    {
        throw std::invalid_argument("Parser choice must be between 1 and 4.");
    }
    else isvalidChoice=true;
    return isvalidChoice;
}

bool InputValidator::isValidInput()
{
    bool isValid=false;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        throw std::runtime_error("Invalid input: unexpected characters or input failure.");
    }
    else isValid=true;

    return isValid;
}