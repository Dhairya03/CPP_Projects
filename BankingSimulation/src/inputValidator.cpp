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
    if(isValidInput(userChoice)){
        return (userChoice == 1 || userChoice == 2) ? true : false;
    }
    else return false;
}

bool InputValidator:: isValidInput(int choice){
    return (std::cin.fail() && std::cin.peek()!='\n')?false:true;
}

bool InputValidator:: isValidInput(char choice){
    return true;
}