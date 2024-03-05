#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <iostream>

class Transaction
{
private:
    int accountNumber;
    int transactionId;
    double transactionAmount;
    double netBalance;
    std::string transactionType;

public:
    int getAccountNumber();

    int getTransactionId();

    double getTransactionAmount();

    double getNetBalance();

    std::string getTransactionType();

    void setAccountNumber(int accountNumber);

    void setTransactionId(int transactionId);

    void setTransactionAmount(double transactionAmount);

    void setNetBalance(double netBalance);

    void setTransactionType(std::string transactionType);
};

#endif