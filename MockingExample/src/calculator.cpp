#include "calculator.h"
#include <iostream>

Calculator::Calculator(IAdd *add, ISub *sub, IMultiply *multiply):add(add),sub(sub),multiply(multiply){}

int Calculator::calculate(int num1, int num2, char operation)
{
    int result = 0;
    if (operation == '+')
    {
        std::cout << "Adding two numbers" << std::endl;
        int sum = add->add(num1, num2) ;
        result=sum*5;

    }
    else if (operation == '-')
    {
        std::cout << "Subtracting two numbers" << std::endl;
        int addresult = sub->sub(num1, num2);
        result = addresult * 3;
    }
    else if (operation == '*')
    {
        std::cout << "mulitplying two numbers" << std::endl;
        int product = multiply->multiply(num1, num2);
        result=product -10;
    }
    else
    {
        std::cout << "Invalid operation choice" << std::endl;
    }
    return result;
}