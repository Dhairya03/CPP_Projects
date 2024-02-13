#ifndef _MATHARITHMETICCLASS_H
#define _MATHARITHMETICCLASS_H

#include "matrixClass.h"

class MatrixArithmetic : public Matrix
{
public:
    MatrixArithmetic(){};
    MatrixArithmetic(int inputSize);

    bool isArithmeticPossible(MatrixArithmetic m2);

    MatrixArithmetic operator+(MatrixArithmetic m2);

    MatrixArithmetic operator*(MatrixArithmetic m2);
 
};

#endif