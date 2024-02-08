#include <iostream>
#include <limits>
#include "matrixArithmeticOperation.h"
#include "inputValidation.h"
#include "matrixProcessingOperation.h"

int main()
{
    int size;
    std::cout << "Enter the size of matrix" << std::endl;
    std::cin >> size;

    char choice;

    if (isValidSize(size))
    {
        do
        {
            double **matrixOne = NULL, **matrixTwo = NULL, **outputMatrix = NULL;

            matrixOne = createMatrix(matrixOne, size);
            matrixTwo = createMatrix(matrixTwo, size);
            outputMatrix = createMatrix(outputMatrix, size);

            if (getInput(matrixOne, size))
            {
                std::cout << "Not a valid input for the matrix!!" << std::endl;
                break;
            }
            if (getInput(matrixTwo, size))
            {
                std::cout << "Not a valid input for the matrix!!" << std::endl;
                break;
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
                delete[] outputMatrix[index];
            }

            delete[] matrixOne;
            matrixOne = NULL;
            delete[] matrixTwo;
            matrixTwo = NULL;
            delete[] outputMatrix;
            outputMatrix = NULL;
            std::cout << "Do you want to continue.\n Press y to continue" << std::endl;
            std::cin >> choice;
        } while (choice == 'y');
        return 1;
    }
    else
    {
        std::cout << "Enter valid size of the array.PLease try again." << std::endl;
    }
    return 0;
}