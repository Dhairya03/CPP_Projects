#include <iostream>
#include <limits>
void printLeftCommonPattern(int column)
{
    if (column % 2 == 0)
        std::cout << "1";
    else
        std::cout << "0";
}

void printRightCommonPattern(int column)
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
                printLeftCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 1; column++)
        {
            if (column <= row || column >= 2 * inputNumber - row)
            {
                printLeftCommonPattern(column - row);
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
                printLeftCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 1; column++)
        {
            if (column <= 2 * inputNumber - row || column >= row)
            {
                printLeftCommonPattern(column - row);
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
                printLeftCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 2; column++)
        {
            if (column <= row || column >= 2 * inputNumber + 1 - row)
            {
                printRightCommonPattern(column - row);
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
                printLeftCommonPattern(column);
            }
            else
                std::cout << " ";
        }

        for (int column = inputNumber + 1; column < 2 * inputNumber + 2; column++)
        {
            if (column <= 2 * inputNumber - row || column > row)
            {
                printRightCommonPattern(column - row);
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

bool checkInteger(std::string inputNumber)
{
    int inputInteger = 0;
    int index = 0;
    if (inputNumber[index] = '-')
        index++;
    while (inputNumber[index] >= '0' && inputNumber[index] <= '9')
    {
        inputInteger = inputInteger * 10 + (inputNumber[index] - '0');
        index++;
    }
    if (inputNumber[index] != '\0')
        return false;
    else
        return true;
}

int main()
{
    std::string inputNumber;
    std::cout << "Enter an integer" << std::endl;
    while (true && inputNumber != "EXIT")
    {
        std::cin >> inputNumber;
        if (!checkInteger(inputNumber))
        {
            if (inputNumber == "EXIT")
            {
                std::cout << "EXITING" << std::endl;
                return 0;
            }
            if (std::cin.eof())
            {
                exit(0);
            }
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error:Not a valid integer!!!Enter valid integer!!!.Please try again.ENter EXIT to exit" << std::endl;
        }
        else
        {
            int inputInteger = std::stoi(inputNumber);
            if (inputInteger < 0 || inputInteger > INT16_MAX)
            {
                std::cout << "Error:Invalid input!! Enter positive integer!!.Please try again. Enter EXIT to exit" << std::endl;
            }
            else
            {
                printPattern(inputInteger);
                return 0;
            }
        }
    }
}
