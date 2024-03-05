#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account
{
private:
    int accountNumber{4000};
    std::string holderName = "";
    long holderContact{};
    std::string holderAddress = "";
    double totalBalance{};

public:
    int getAccountNumber();

    std::string getHolderName();

    long getHolderContact();

    std::string getHolderAddress();

    double getTotalBalance();

    void setAccountNumber(int accountNumber);

    void setHolderName(const std::string &holderName);

    void setHolderContact(long holderContact);

    void setHolderAddress(const std::string &holderAddress);

    void setTotalBalance(double totalBalance);
};
#endif