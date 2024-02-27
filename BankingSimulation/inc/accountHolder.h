#ifndef ACCHOLDER_H
#define ACCHOLDER_H

#include<iostream>
#include<bank.h>
#include<transaction.h>

class AccountHolder : public Bank
{
public:
    int accountNumber{4000};
    std::string holderName;
    long holderContact;
    std::string holderAddress;
    double totalBalance{};

    void showOperationChoices();

    void performOperation(int operationChoice);

    void seeUserList();

    void seeParticularUser();

    int createAccount();

    int closeAccount();
};

#endif