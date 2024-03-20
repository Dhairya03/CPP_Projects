#ifndef CALCULATE_H
#define CALCULATE_H

#include "IAdd.h"
#include "ISub.h"
#include "IMultiply.h"
#include "add.h"
#include "sub.h"
#include "multiply.h"

class Calculator
{
    IAdd *add = nullptr;
    ISub *sub = nullptr;
    IMultiply *multiply = nullptr;

public:
    Calculator(IAdd *, ISub *, IMultiply *);

    int calculate(int, int, char);
};

#endif