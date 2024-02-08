#include <iostream>
#include <limits>
#include "matrixArithmeticOperation.h"
#include "inputValidation.h"
#include "matrixProcessingOperation.h"

int main()
{
    int size;
    char choice;
    double **matrixOne = NULL, **matrixTwo = NULL, **outputMatrix = NULL;

    do
    {
        std::cout << "Enter the size of matrix" << std::endl;
        std::cin >> size;

        if (isValidSize(size))
        {
            if (createMatrix(matrixOne, size) != NULL)
            {
                matrixOne = createMatrix(matrixOne, size);
                std::cout << "Matrix One created successfully" << std::endl;
            }

            if (createMatrix(matrixTwo, size) != NULL)
            {
                matrixTwo = createMatrix(matrixTwo, size);
                std::cout << "Matrix Two created successfully" << std::endl;
            }

            if (getInput(matrixOne, size))
            {
                std::cout << "Not a valid input for the matrix!!" << std::endl;
            }

            if (getInput(matrixTwo, size))
            {
                std::cout << "Not a valid input for the matrix!!" << std::endl;
            }

            printMatrix(matrixOne, size);
            printMatrix(matrixTwo, size);

            std::cout << "Addition of matrices" << std::endl;

            if (addMatrices(matrixOne, matrixTwo, size) != NULL)
            {
                outputMatrix = addMatrices(matrixOne, matrixTwo, size);

                printMatrix(outputMatrix, size);
            }

            std::cout << "Multiplication of matrices" << std::endl;

            if (multiplyMatrices(matrixOne, matrixTwo, size) != NULL)
            {
                outputMatrix = multiplyMatrices(matrixOne, matrixTwo, size);

                printMatrix(outputMatrix, size);
            }

            for (int index = 0; index < size; index++)
            {
                delete[] matrixOne[index];
                delete[] matrixTwo[index];
                delete[] outputMatrix[index];
            }

            delete[] matrixOne;
            matrixOne = NULL;
            delete[] matrixTwo;
            matrixTwo = NULL;
            delete[] outputMatrix;
            outputMatrix = NULL;
        }
        else
        {
            std::cout << "Not a valid size of the array." << std::endl;
        }
        std::cout << "Do you want to continue.\nPress y to continue" << std::endl;
        std::cin >> choice;
    } while (choice == 'y');
    return 0;
}