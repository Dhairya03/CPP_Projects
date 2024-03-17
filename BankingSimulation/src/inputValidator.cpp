#include "inputValidator.h"
#include <limits>

int InputValidator::getUserChoice()
{
    return userChoice;
}

void InputValidator::setUserChoice(int userChoice)
{
    this->userChoice=userChoice;
}

int InputValidator::getOperatorChoice()
{
    return operationChoice;
}

void InputValidator::setOperatorChoice(int operatorChoice)
{
    this->operationChoice=operatorChoice;
}

char InputValidator::getContinueChoice()
{
    return continueChoice;
}

void InputValidator::setContinueChoice(char continueChoice)
{
    this->continueChoice=continueChoice;
}

bool InputValidator::isValidUserChoice()
{
    return (userChoice == 1 || userChoice == 2) ? true : false;
}

bool InputValidator::isValidInput(int input)
{
    bool isValid = true;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout<<"Please enter valid input integer."<<std::endl;
        isValid = false;
    }
    else
        isValid = true;
    return isValid;
}

bool InputValidator::isValidInput(double input)
{
    bool isValid = true;
    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isValid = false;
    }
    else
        isValid = true;
    return isValid;
}

bool InputValidator::isValidInput(char choice)
{
    return (choice == 'y' || choice == 'n') ? true : false;
}