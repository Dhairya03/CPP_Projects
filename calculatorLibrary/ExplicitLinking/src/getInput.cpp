#include<iostream>
#include "validateInput.h"
#include<limits>

int getNumericInput(double &inputNumber, std::string &inputString)
{
    int validBit = 1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter input number :" << std::endl;
    std::getline(std::cin, inputString);
    if (isEmptyString(inputString))
    {
        std::cout << "Undefined expression!! Enter valid number!!!" << std::endl;
        validBit = 0;
    }
    else if (!isValidInputNumber(inputString))
    {
        std::cout << "Invalid input number!!!Please try again." << std::endl;
        validBit = 0;
    }
    else
    {
        inputNumber = std::stof(inputString);
    }
    return validBit;
}

int getInput(double &inputNumberOne, double &inputNumberTwo, char &operation)
{
    std::string inputStringOne, inputStringTwo;
    int validBit = 0;
    while (true)
    {
        if (!getNumericInput(inputNumberOne, inputStringOne))
            break;
        std::cout << "Enter operation to be performed:\nChoose from below operations: \n +, -, *, /" << std::endl;
        std::cin >> operation;
        if (!isValidOperator(operation))
        {
            std::cout << "Invalid Operator!!! Please try again!!!" << std::endl;
            break;
        }
        validBit = getNumericInput(inputNumberTwo, inputStringTwo);
        break;
    }
    return validBit;
}

void print(double inputNumberOne, double inputNumberTwo, char operation)
{
    std::cout << "Mathematical expression is:" << std::endl;
    std::cout << inputNumberOne << " " << operation << " " << inputNumberTwo << std::endl;
}