#ifndef MOCK_ACCOUNT_HOLDER_H
#define MOCK_ACCOUNT_HOLDER_H

#include <gmock/gmock.h>
#include "IAccountHolder.h"

class MockAccountHolder : public IAccountHolder
{
public:
    MOCK_METHOD(int, withdrawMoney, (Bank &), (override));
    MOCK_METHOD(int, depositMoney, (Bank &), (override));
    MOCK_METHOD(bool, findStatement, (Bank &, Transaction &, int accountNumber), (override));
    MOCK_METHOD(int, getMiniBankStatement, (Bank &), (override));
    MOCK_METHOD(int, getBankStatement, (Bank &), (override));
    MOCK_METHOD(int, showBalance, (Bank &), (override));
    MOCK_METHOD(bool, logout, (), (override));
};

#endif