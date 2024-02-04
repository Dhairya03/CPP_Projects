#include <iostream>
#include <limits>
#include "mathFunctions.h"
#include "calculateFunction.h"
#include "validateInput.h"
#include "getInput.h"
#include <dlfcn.h>

typedef double (*mathFunction)(double, double);

int main()
{
    void *handle = dlopen("../../../lib_Explicit.so", RTLD_LAZY);
    if (!handle)
    {
        std::cout << "Error loading shared library" << std::endl;
        return 1;
    }

    mathFunction add = reinterpret_cast<mathFunction>(dlsym(handle, "add"));
    mathFunction subtract = reinterpret_cast<mathFunction>(dlsym(handle, "subtract"));
    mathFunction multiply = reinterpret_cast<mathFunction>(dlsym(handle, "multiply"));
    mathFunction divide = reinterpret_cast<mathFunction>(dlsym(handle, "divide"));

    if (!add || !subtract || !multiply || !divide)
    {
        std::cout << "Error finding the function" << std::endl;
        dlclose(handle);
        return 1;
    }

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
