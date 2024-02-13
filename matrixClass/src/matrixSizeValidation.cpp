#include<iostream>
#include<limits>
#include"matrixSizeValidation.h"

bool isValidInput(int inputNumber)
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

bool isValidSize(int size)
{
    return (!isValidInput(size) || size <= 0) ? false : true;
}

int getSize()
{
    int size;
    while (true)
    {
        std::cout << "Enter size of matrix of type [n x n]" << std::endl;
        std::cin >> size;
        if (isValidSize(size)){
            if(size==0) std::cout<<"Enter valid size of the matrix"<<std::endl;
            else break;
        }
    }
    return size;
}

bool isValidChoice(char choice)
{
    return (choice == 'y' || choice == 'e') ? true : false;
}