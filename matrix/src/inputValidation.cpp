#include <iostream>
#include <limits>
#include "inputValidation.h"

bool isValidIntegerInput(int inputNumber)
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

bool isValidDoubleInput(double inputNumber)
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
    return (!isValidIntegerInput(size) || size <= 0) ? false : true;
}