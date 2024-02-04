#include <iostream>

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