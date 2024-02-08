#include "matrixProcessingOperation.h"
#include "matrixArithmeticOperation.h"

double **addMatrices(double **matrixOne, double **matrixTwo, int size)
{
    double **outputMatrix = createMatrix(outputMatrix, size);
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            *(*(outputMatrix + row) + column) = *(*(matrixOne + row) + column) + *(*(matrixTwo + row) + column);
        }
    }

    return outputMatrix;
}

double **multiplyMatrices(double **matrixOne, double **matrixTwo, int size)
{
    double **outputMatrix = createMatrix(outputMatrix, size);
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            double value = 0.0;
            for (int index = 0; index < size; index++)
            {
                value += *(*(matrixOne + row) + index) * *(*(matrixTwo + index) + column);
            }
            outputMatrix[row][column] = value;
        }
    }

    return outputMatrix;
}
