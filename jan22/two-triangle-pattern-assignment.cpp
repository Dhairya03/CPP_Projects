#include <iostream>
#include <limits>
void printCommonPattern(int column)
{
    if (column % 2 == 0)
        std::cout << "1";
    else
        std::cout << "0";
}

void printAnotherCommonPattern(int column)
{
    if ((column) % 2 == 0)
        std::cout << "0";
    else
        std::cout << "1";
}

void printEvenPattern(int inputNumber)
{
    for (int row = 0; row < inputNumber + 1; row++)
    {
        for (int column = 0; column < inputNumber + 1; column++)
        {
            if (column <= row || column >= 2 * inputNumber - row)
            {
                printCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 1; column++)
        {
            if (column <= row || column >= 2 * inputNumber - row)
            {
                printCommonPattern(column - row);
            }
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    for (int row = inputNumber + 1; row < 2 * inputNumber + 1; row++)
    {
        for (int column = 0; column < inputNumber + 1; column++)
        {
            if (column <= 2 * inputNumber - row || column >= row)
            {
                printCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 1; column++)
        {
            if (column <= 2 * inputNumber - row || column >= row)
            {
                printCommonPattern(column - row);
            }
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void printOddPattern(int inputNumber)
{
    for (int row = 0; row < inputNumber + 1; row++)
    {
        for (int column = 0; column < inputNumber + 1; column++)
        {
            if (column <= row || column >= 2 * inputNumber + 1 - row)
            {
                printCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 2; column++)
        {
            if (column <= row || column >= 2 * inputNumber + 1 - row)
            {
                printAnotherCommonPattern(column - row);
            }
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    for (int row = inputNumber + 1; row < 2 * inputNumber + 1; row++)
    {
        for (int column = 0; column < inputNumber + 1; column++)
        {
            if (column <= 2 * inputNumber - row || column > row)
            {
                printCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 2; column++)
        {
            if (column <= 2 * inputNumber - row || column > row)
            {
                printAnotherCommonPattern(column - row);
            }
            else
                std::cout << " ";
        }
        std::cout << std::endl;
    }
}

void printPattern(int inputNumber)
{
    if (inputNumber % 2 == 0)
    {
        printEvenPattern(inputNumber);
    }
    else
    {
        printOddPattern(inputNumber);
    }
}
int main()
{
    int inputNumber = -1;
    std::cout << "Enter an integer" << std::endl;
    while (true)
    {
        std::cin >> inputNumber;
        if (std::cin.fail())
        {
            std::cout << inputNumber;
            if (std::cin.eof())
            {
                exit(0);
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (inputNumber < 0 || inputNumber >= INT16_MAX)
        {
            std::cout << "Invalid input!!!.Please try again.Enter " << std::endl;
        }
        else
        {
            printPattern(inputNumber);
            return 0;
        }
    }
}
