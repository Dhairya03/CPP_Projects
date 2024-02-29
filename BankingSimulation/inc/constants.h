#ifndef CONSTANTS_H
#define CONSTANTS_H

#include "admin.h"

// class Constants
// {
// public:
//     Admin adminData=Admin(101, 123456);
// };

extern Admin adminData;

enum UserTypes
{
    admin = 1,
    accountHolder = 2
};

#endif