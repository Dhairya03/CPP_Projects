#include <iostream>
#include "mathFunctions.h"

int calculate(double inputNumberOne, double inputNumberTwo, char operation)
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