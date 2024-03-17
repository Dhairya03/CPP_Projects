#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "admin.h"

extern Admin adminData;

const int initialAccountNumber=4000;

enum UserTypes
{
    admin = 1,
    accountHolder = 2
};

#endif