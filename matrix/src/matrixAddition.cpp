#include "matrixAddition.h"

double **addMatrices(double **matrixOne, double **matrixTwo, int size, double **outputMatrix)
{
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            *(*(outputMatrix + row) + column) = *(*(matrixOne + row) + column) + *(*(matrixTwo + row) + column);
        }
    }

    return outputMatrix;
}