#ifndef INPUTVALIDATOR_H
#define INPUTVALIDATOR_H

#include <iostream>

class InputValidator
{
private:
    int userChoice{};
    int operationChoice{};
    char continueChoice{};

public:
    int getUserChoice();

    void setUserChoice(int userChoice);

    int getOperatorChoice();

    void setOperatorChoice(int operatorChoice);

    bool isValidUserChoice();

    char getContinueChoice();

    void setContinueChoice(char continueChoice);

    bool isValidInput(int choice);

    bool isValidInput(double choice);

    bool isValidInput(char choice);
};

#endif