#ifndef ACCOUNTS_H
#define ACCOUNTS_H

#include <vector>
#include "account.h"

class Accounts
{
public:
    std::vector<Account> accounts;

    void createAccount(int accNumber, const std::string& name, long contact, const std::string& address, double balance) {
                // If the account doesn't exist, create a new account
        // accounts.push_back(Account(accNumber, name, contact, address, balance));
        std::cout << "Account created successfully with account number " << accNumber << std::endl;
    }

};

#endif