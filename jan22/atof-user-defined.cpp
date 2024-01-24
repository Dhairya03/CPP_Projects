#include <iostream>
#include <cmath>

int checkSign(double &floatValue, std::string &inputString, int &index)
{
    int sign=1;
    if (inputString[index] == '-' || inputString[index] == '+')
    {
        if (inputString[index] == '-')
            sign = -1;
        else
            sign = 1;
        index++;
    }
    return sign;
}

void checkDecimal(double &floatValue, std::string &inputString, int &index)
{
    double decimal = 0.1;
    if (inputString[index] == '.')
    {
        index++;
        while (inputString[index] >= '0' && inputString[index] <= '9')
        {
            floatValue += decimal * (inputString[index] - '0');
            decimal *= decimal;
            index++;
        }
    }
}

void checkExponent(double &floatValue, std::string &inputString, int &index)
{
    int exponentSign = 1;
    int exponent = 0;
    if (inputString[index] == 'e')
    {
        index++;
        exponentSign=checkSign(floatValue,inputString,index);

        while (inputString[index] >= '0' && inputString[index] <= '9')
        {
            exponent = exponent * 10 + (inputString[index] - '0');
            index++;
        }
    }
    if (exponent != 0)
    {
        floatValue = floatValue * std::pow(10, exponent * exponentSign);
    }
}

double atof(std::string &inputString)
{
    double floatValue = 0.0;
    int sign = 1;
    int index = 0;

    while (inputString[index] == ' ')
    {
        index++;
    }

    sign=checkSign(floatValue,inputString,index);

    while (inputString[index] >= '0' && inputString[index] <= '9')
    {
        floatValue = floatValue * 10 + (inputString[index] - '0');
        index++;
    }

    checkDecimal(floatValue, inputString, index);

    checkExponent(floatValue, inputString, index);

    floatValue = floatValue * sign;

    if (floatValue == -0)
        return 0;

    return floatValue;
}

int main()
{
    std::string inputString;
    std::cout << "Enter input string" << std::endl;
    std::getline(std::cin, inputString);
    std::cout << "Input String:" << inputString << std::endl;
    std::cout << "Float Value: " << atof(inputString) << std::endl;
    return 0;
}