#ifndef IBANK_H
#define IBANK_H

#include <iostream>
#include <vector>
#include "account.h"
#include "transaction.h"

class IBank {
public:
    virtual std::vector<Account>& getAccountHolderData() = 0;
    virtual std::vector<Transaction>& getTransactionDetails() = 0;
};

#endif