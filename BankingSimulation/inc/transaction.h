#ifndef TRANSACTION_H
#define TRANSACTION_H

#include<iostream>

class Transaction
{
public:
    int accountNumber{};
    int transactionId;
    double transactionAmount;
    double netBalance;
    std::string transactionType;

    Transaction(int accNum, int transId, double transAmount, double netBal, std::string transType);
};

#endif