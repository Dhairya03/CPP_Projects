#include <iostream>
#include "add.h"
#include "sub.h"
#include "multiply.h"
#include "calculator.h"

int main()
{
    Add addition;
    Sub subtraction;
    Multiply multiplication;
    Calculator calculator(&addition,&subtraction,&multiplication);

    std::cout << "Calculator" << std::endl;
    int num1, num2;
    std::cout << "Enter two numbers" << std::endl;
    char operation;
    std::cin >> num1;
    std::cin >> num2;
    std::cout << "Enter operation +,-,or *" << std::endl;
    std::cin >> operation;
    calculator.calculate(num1, num2, operation);
    return 0;
}