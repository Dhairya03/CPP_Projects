#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class Transaction
{
private:
    int transactionId;
    double transactionAmount;
    double netBalance;
    std::string transactionType;

public:

    int getTransactionId();

    double getTransactionAmount();

    double getNetBalance();

    std::string getTransactionType();

    void setTransactionId(int transactionId);

    void setTransactionAmount(double transactionAmount);

    void setNetBalance(double netBalance);

    void setTransactionType(std::string transactionType);
};

#endif