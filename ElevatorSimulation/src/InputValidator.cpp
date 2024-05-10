#include "InputValidator.h"
#include <iostream>
#include <limits>

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