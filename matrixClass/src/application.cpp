#include <iostream>
#include <limits>
#include "matrixClass.h"
#include "matrixArithmeticClass.h"
#include "matrixSizeValidation.h"

int main()
{
    char choice;
    int size;

    do
    {
        MatrixArithmetic matrix1(getSize());
        matrix1.getInput();
        matrix1.printMatrix();

        MatrixArithmetic matrix2(getSize());
        matrix2.getInput();
        matrix2.printMatrix();

        if (matrix1.isArithmeticPossible(matrix2))
        {
            std::cout << "Addition of matrices" << std::endl;

            MatrixArithmetic output;
            output = matrix1 + matrix2;
            output.printMatrix();

            std::cout << "Multiplication of matrices" << std::endl;

            output = matrix1 * matrix2;
            output.printMatrix();

            std::cout << "Addition and Multiplication successfully done" << std::endl;
        }
        else
        {
            std::cout << "Addition and multiplication for these matrices are not possible due to different size of matrix." << std::endl;
            std::cout << "-------------------------------------------------------------" << std::endl;
        }

        std::cout << "Do you want to continue.\nPress y to continue\nPress e to exit." << std::endl;

        while (true)
        {
            std::cin >> choice;

            if (isValidChoice(choice))
                break;
            else
                std::cout << "Enter valid choice to proceed" << std::endl;
        }

    } while (choice == 'y');

    return 0;
}