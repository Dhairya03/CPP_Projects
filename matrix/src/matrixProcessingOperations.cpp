
#include<iostream>
#include"inputValidation.h"

double **createMatrix(double **inputMatrix, int size)
{
    inputMatrix = new double *[size];
    for (int index = 0; index < size; index++)
    {
        inputMatrix[index] = new double[size];
    }
    return inputMatrix;
}

int getInput(double **inputMatrix, int size)
{
    int toReturn=0;
    if (inputMatrix == NULL)
    {
        toReturn=1;
        std::cout << "No matrix found..." << std::endl;
    }
    else
    {
        std::cout << "Enter elements of matrix" << std::endl;
        for (int row = 0; row < size; row++)
        {
            for (int column = 0; column < size; column++)
            {
                while(true){
                std::cin >> *(*(inputMatrix + row) + column);
                if (!isValidDouble(*(*(inputMatrix + row) + column)))
                {
                    std::cout<<"Invalid Input. Please try again."<<std::endl;
                    toReturn=1;
                    break;
                }
                }
            }
        }
    }
    return toReturn;
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