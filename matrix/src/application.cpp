#include <iostream>
#include <limits>
#include "matrixAddition.h"
#include "matrixMultiplication.h"
#include "inputValidation.h"

double **createMatrix(double **inputMatrix, int size)
{
    inputMatrix = new double *[size];
    for (int index = 0; index < size; index++)
    {
        inputMatrix[index] = new double[size];
    }
    std::cout << "Matrix created successfully" << std::endl;
    return inputMatrix;
}

int getInput(double **inputMatrix, int size)
{
    if (inputMatrix == NULL)
    {
        std::cout << "No matrix found Please try again." << std::endl;
    }
    else
    {
        std::cout << "Enter elements of matrix" << std::endl;
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                std::cin >> *(*(inputMatrix + row) + column);
                if (!isValidDoubleInput(*(*(inputMatrix + row) + column)))
                {
                    // std::cout<<"Invalid Input. Please try again."<<std::endl;
                    return 1;
                }
            }
        }
    }
    return 0;
}

void printMatrix(double **matrix, int size)
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
}

int main()
{
    int size;
    std::cout << "Enter the size of matrix" << std::endl;
    std::cin >> size;

    if(isValidSize(size))
    {
        double **matrixOne = NULL, **matrixTwo = NULL, **outputMatrix = NULL;

        matrixOne = createMatrix(matrixOne, size);
        matrixTwo = createMatrix(matrixTwo, size);
        outputMatrix = createMatrix(outputMatrix, size);

        if (getInput(matrixOne, size))
        {
            std::cout << "Not a valid input for the matrix!!" << std::endl;
            return 1;
        }
        if (getInput(matrixTwo, size))
        {
            std::cout << "Not a valid input for the matrix!!" << std::endl;
            return 1;
        }

        printMatrix(matrixOne, size);
        printMatrix(matrixTwo, size);

        if (addMatrices(matrixOne, matrixTwo, size, outputMatrix) != NULL)
        {
            std::cout << "Addition of matrices" << std::endl;

            printMatrix(outputMatrix, size);
        }

        if (multiplyMatrices(matrixOne, matrixTwo, size, outputMatrix) != NULL)
        {
            std::cout << "Multiplication of matrices" << std::endl;

            printMatrix(outputMatrix, size);
        }

        for (int index = 0; index < size; index++)
        {
            delete[] matrixOne[index];
            delete[] matrixTwo[index];
        }

        delete[] matrixOne;
        delete[] matrixTwo;
    }
    else
    {
        std::cout << "Enter valid size of the array.PLease try again." << std::endl;
    }
    return 0;
}