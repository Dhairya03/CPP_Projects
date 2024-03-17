#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include "transaction.h"

class Account
{
private:
    int accountNumber{};
    std::string holderName = "";
    double totalBalance{};

public:
    std::vector<Transaction> transactions;

    int getAccountNumber();

    std::string getHolderName();

    double getTotalBalance();

    std::vector<Transaction> getTransactions() const;

    void setTransactions(const std::vector<Transaction> &newTransactions);

    void setAccountNumber(int accountNumber);

    void setHolderName(const std::string &holderName);

    void setTotalBalance(double totalBalance);
};
#endif