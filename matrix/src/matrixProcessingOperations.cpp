
#include<iostream>
#include"inputValidation.h"

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
                if (!isValidDouble(*(*(inputMatrix + row) + column)))
                {
                    std::cout<<"Invalid Input. Please try again."<<std::endl;
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