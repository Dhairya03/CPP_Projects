#ifndef ACCHOLDER_H
#define ACCHOLDER_H

#include <iostream>
#include "bankUser.h"
#include "bank.h"

class AccountHolder : public BankUser
{
public:
    bool logout();
};

#endif