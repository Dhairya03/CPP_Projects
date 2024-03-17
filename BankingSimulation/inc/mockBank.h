#include "bank.h"
#include <gmock/gmock.h>

class MockBank : public Bank {
public:
    std::vector<Account> mockAccountData;
    std::vector <Transaction> mockTransactionData;
};