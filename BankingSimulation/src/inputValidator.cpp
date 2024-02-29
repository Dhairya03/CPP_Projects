#include "inputValidator.h"
#include <limits>

int InputValidator::getUserChoice()
{
    while(true){
        std::cin >> userChoice;
        if(isValidInput(userChoice))break;
        else std::cout<<"Enter Valid user choice"<<std::endl;
    }
    
    return userChoice;
}

int InputValidator::getOperatorChoice()
{
    while(true){
        std::cin >> operationChoice;
        if(isValidInput(operationChoice))break;
        else std::cout<<"Enter Valid user choice"<<std::endl;
    }
    return operationChoice;
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