#include "IBank.h"
#include <gmock/gmock.h>

class MockBank : public IBank {
public:
    MOCK_METHOD(std::vector<Account>&, getAccountHolderData, (), (override));
    MOCK_METHOD(std::vector<Transaction>&, getTransactionDetails, (), (override));
};