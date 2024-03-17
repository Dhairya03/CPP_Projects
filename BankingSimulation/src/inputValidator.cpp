#include "inputValidator.h"
#include <limits>

int InputValidator::getUserChoice()
{
    return userChoice;
}

void InputValidator::setUserChoice()
{
    while (true)
    {
        std::cin >> userChoice;
        if (isValidInput(userChoice))
        {
            break;
        }
        else
            std::cout << "Enter Valid user choice" << std::endl;
    }
}

int InputValidator::getOperatorChoice()
{
    return operationChoice;
}

void InputValidator::setOperatorChoice()
{
    while (true)
    {
        std::cin >> operationChoice;
        if (isValidInput(operationChoice))
        {
            break;
        }
        else
            std::cout << "Enter Valid user choice" << std::endl;
    }
}

char InputValidator::getContinueChoice()
{
    return continueChoice;
}

void InputValidator::setContinueChoice()
{
    while (true)
    {
        std::cin >> continueChoice;
        if (isValidInput(continueChoice))
        {
            break;
        }
        else
            std::cout << "Enter valid choice.Please try again." << std::endl;
    }
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