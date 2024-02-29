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

    void performOperation(int operationChoice);

    void seeUserList();

    void seeParticularUser();

    // int createAccount();

    int closeAccount();
    bool logout();
};

#endif