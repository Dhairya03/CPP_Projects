#include <iostream>
#include <limits>
#include "inputValidator.h"

bool InputValidator::isValidLane(int lane)
{
    bool isvalidLane = false;
    if (lane < 1 || lane > 4)
    {
        isvalidLane = false;
    }
    else
        isvalidLane = true;
    return isvalidLane;
}

bool InputValidator::isValidInput()
{
    bool isValid = false;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    else
        isValid = true;
    return isValid;
}