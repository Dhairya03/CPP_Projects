#include <iostream>
#include <limits>
#include "mathFunctions.h"
#include "calculateFunction.h"
#include "validateInput.h"
#include "getInput.h"

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
