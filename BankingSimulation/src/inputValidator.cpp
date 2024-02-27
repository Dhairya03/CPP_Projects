#include "inputValidator.h"

int InputValidator::getUserChoice()
{
    std::cin >> userChoice;
    return userChoice;
}

int InputValidator::getOperatorChoice()
{
    std::cin >> operationChoice;
    return operationChoice;
}

bool InputValidator::isValidUserChoice()
{

    return (userChoice == 1 || userChoice == 2) ? true : false;
}