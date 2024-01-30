#include <iostream>
#include <limits>
#include "header.h"

int calculate(double &inputNumberOne, double &inputNumberTwo, char operation)
{
    switch (operation)
    {
    case '+':
        std::cout << "RESULT : " << add(inputNumberOne, inputNumberTwo) << std::endl;
        break;
    case '-':
        std::cout << "RESULT : " << subtract(inputNumberOne, inputNumberTwo) << std::endl;
        break;
    case '*':
        std::cout << "RESULT : " << multiply(inputNumberOne, inputNumberTwo) << std::endl;
        break;
    case '/':
        if (inputNumberTwo != 0)
        {
            std::cout << "RESULT : " << divide(inputNumberOne, inputNumberTwo) << std::endl;
        }
        else
        {
            std::cout << "Division by zero is undefined" << std::endl;
        }
        break;
    default:
        std::cout << "Invalid operator choice.Please try again!!!" << std::endl;
    }
    return 1;
}

bool isNegative(std::string inputNumber, int index)
{
    return (inputNumber[index] == '-') ? true : false;
}

bool isDecimal(std::string inputNumber, int index)
{
    return (inputNumber[index] == '.') ? true : false;
}

bool isValidInputNumber(std::string inputNumber)
{
    int index = 0;
    while (inputNumber[index] == ' ')
        index++;

    if (isNegative(inputNumber, index))
    {
        index++;
    }

    while (inputNumber[index] >= '0' && inputNumber[index] <= '9')
    {
        index++;
    }

    if (isDecimal(inputNumber, index))
    {
        index++;
        while (inputNumber[index] >= '0' && inputNumber[index] <= '9')
        {
            index++;
        }
    }

    while (inputNumber[index] == ' ')
        index++;

    return (inputNumber[index] != '\0') ? false : true;
}

bool isValidOperator(char operation)
{
    return (operation == '+' || operation == '-' || operation == '*' || operation == '/') ? true : false;
}

bool isEmptyString(std::string inputString)
{
    int index = 0;
    while (inputString[index] == ' ')
        index++;
    return (inputString[index] == '\0') ? true : false;
}

int getNumericInput(double &inputNumber, std::string &inputString)
{
    int flag = 1;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter input number :" << std::endl;
    std::getline(std::cin, inputString);

    if (isEmptyString(inputString))
    {
        std::cout << "Undefined expression!! Enter valid number!!!" << std::endl;
        flag = 0;
    }
    else if (!isValidInputNumber(inputString))
    {
        std::cout << "Invalid input number!!!Please try again." << std::endl;
        flag = 0;
    }
    else
    {
        inputNumber = std::stof(inputString);
    }
    return flag;
}

int getInput(double &inputNumberOne, double &inputNumberTwo, char &operation)
{
    std::string inputStringOne, inputStringTwo;
    int flag = 0;

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

        flag = getNumericInput(inputNumberTwo, inputStringTwo);
        break;
    }
    return flag;
}

void print(double num1, double num2, char op)
{
    std::cout << "Mathematical expression is:" << std::endl;
    std::cout << num1 << " " << op << " " << num2 << std::endl;
}

int main()
{
    double inputNumberOne, inputNumberTwo;
    char operation;
    char choice;

    do
    {
        if (getInput(inputNumberOne, inputNumberTwo, operation))
        {
            std::cout << "Input taken successfully" << std::endl;

            print(inputNumberOne, inputNumberTwo, operation);

            calculate(inputNumberOne, inputNumberTwo, operation);
        }
        std::cout << "Do you want to continue.\nPress y to continue.\nPress exit to exit." << std::endl;
        std::cin >> choice;
    } while (choice == 'y');

    return 0;
}
