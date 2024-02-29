#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <iostream>

class InputValidator
{

public:
    int userChoice{};
    int operationChoice{};
    char continueChoice{};

    int getUserChoice();

    int getOperatorChoice();

    bool isValidUserChoice();

    bool isValidInput(int choice);

    bool isValidInput(double choice);

    bool isValidInput(char choice);
};

#endif