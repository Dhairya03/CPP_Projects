#include <iostream>
#include <limits>
#include "matrixClass.h"

int Matrix::getInput()
{
    int isValid = 0;

    if (matrix == NULL)
    {
        isValid = 1;
        std::cout << "No matrix found..." << std::endl;
    }
    else
    {
        std::cout << "Enter elements of matrix" << std::endl;
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                while (true)
                {
                    std::cin >> *(*(matrix + row) + column);
                    if (!isValidInput(*(*(matrix + row) + column)))
                    {
                        std::cout << "Invalid Input. Please try again." << std::endl;
                        isValid = 1;
                    }
                    else
                        break;
                }
            }
        }
    }

    return isValid;
}

bool Matrix::isValidInput(double inputNumber)
{
    bool isValid = true;

    if (std::cin.fail() || std::cin.peek() != '\n')
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        isValid = false;
    }
    else
        isValid = true;

    return isValid;
}

double **Matrix::createMatrix(double **inputMatrix, int size)
{
    inputMatrix = new double *[size];
    for (int index = 0; index < size; index++)
    {
        inputMatrix[index] = new double[size];
    }
    return inputMatrix;
}

void Matrix::printMatrix()
{
    std::cout << "Elements of matrix are" << std::endl;
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            std::cout << matrix[row][column] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "-------------------------------------------------------------" << std::endl;
}
