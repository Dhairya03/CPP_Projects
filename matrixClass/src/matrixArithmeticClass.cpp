#include "matrixArithmeticClass.h"

MatrixArithmetic::MatrixArithmetic(int inputSize)
{
    size = inputSize;

    if (createMatrix(matrix, size) != NULL)
    {
        matrix = createMatrix(matrix, size);
    }
}

bool MatrixArithmetic::isArithmeticPossible(MatrixArithmetic matrix2)
{
    return (size == matrix2.size) ? true : false;
}

MatrixArithmetic MatrixArithmetic::operator+(MatrixArithmetic matrix2)
{
    MatrixArithmetic outputMatrix;

    outputMatrix.size = size;
    outputMatrix.matrix = createMatrix(outputMatrix.matrix, outputMatrix.size);

    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            outputMatrix.matrix[row][column] = matrix[row][column] + matrix2.matrix[row][column];
        }
    }

    return outputMatrix;
}

MatrixArithmetic MatrixArithmetic::operator*(MatrixArithmetic matrix2)
{
    MatrixArithmetic outputMatrix;

    outputMatrix.size = size;
    outputMatrix.matrix = createMatrix(outputMatrix.matrix, outputMatrix.size);
    
    for (int row = 0; row < size; row++)
    {
        for (int column = 0; column < size; column++)
        {
            double value = 0.0;
            for (int index = 0; index < size; index++)
            {
                value += *(*(matrix + row) + index) * *(*(matrix2.matrix + index) + column);
            }
            outputMatrix.matrix[row][column] = value;
        }
    }

    return outputMatrix;
}
