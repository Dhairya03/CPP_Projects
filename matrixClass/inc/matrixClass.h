#ifndef _MATRIXCLASS_H
#define _MATRIXCLASS_H
#include<iostream>

class Matrix
{
protected:
    int size;
    double **matrix = NULL;

public:
    Matrix(){};

    int getInput();

    bool isValidInput(double inputNumber);
 
    double **createMatrix(double **inputMatrix, int size);

    void printMatrix();
   
};

#endif
