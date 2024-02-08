#include <iostream>
#include <limits>
#include "inputValidation.h"

bool isValidInteger(int inputNumber)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cout << "Invalid Input..PLease try again.." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

bool isValidDouble(double inputNumber)
{
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cout << "Invalid Input..PLease try again.." << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    else
        return true;
}

bool isValidSize(int size)
{
    return (!isValidInteger(size) || size <= 0) ? false : true;
}