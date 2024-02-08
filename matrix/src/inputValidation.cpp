#include <iostream>
#include <limits>
#include "inputValidation.h"

bool isValidInteger(int inputNumber)
{
    bool toReturn = true;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        toReturn = false;
    }
    else
        toReturn = true;

    return toReturn;
}

bool isValidDouble(double inputNumber)
{
    bool toReturn = true;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        toReturn = false;
    }
    else
        toReturn = true;
        
    return toReturn;
}

bool isValidSize(int size)
{
    return (!isValidInteger(size) || size <= 0) ? false : true;
}