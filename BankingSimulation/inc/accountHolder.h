#ifndef ACCHOLDER_H
#define ACCHOLDER_H

#include<iostream>

#include"bank.h"

// #ifndef TRANSACTION_H
// #define TRANSACTION_H

// #include<transaction.h>

// #endif

class AccountHolder : public Bank
{
public:

    void showOperationChoices();

    void performOperation(int operationChoice,Bank &b);

    // void seeUserList(Bank &b);

    // void seeParticularUser(Bank &b);

    // int createAccount();

    int closeAccount(Bank &b);
    bool logout();
};

#endif