#ifndef ACCOUNT_H
#define ACCOUNT_H

#include<iostream>

class Account{
    public:
     int accountNumber{4000};
    std::string holderName;
    long holderContact;
    std::string holderAddress;
    double totalBalance{};
    
};
#endif