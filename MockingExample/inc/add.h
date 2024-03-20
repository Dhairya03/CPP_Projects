#ifndef ADD_H
#define ADD_H
#include"IAdd.h"

class Add:public IAdd{
    public:
    int add(int ,int);
};

#endif