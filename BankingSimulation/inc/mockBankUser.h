#ifndef MOCK_BANK_USER_H
#define MOCK_BANK_USER_H

#include "bankUser.h"
#include <gmock/gmock.h>
#include "bank.h"
#include "admin.h"

using ::testing::_;
using ::testing::Invoke;

class MockBankUser : public BankUser {
public:
    MOCK_METHOD(bool, login, (), (override));
    MOCK_METHOD(int, withdrawMoney, (Bank&), (override));
    MOCK_METHOD(int, depositMoney, (Bank&), (override));
    MOCK_METHOD(int, getMiniBankStatement, (Bank&), (override));
    MOCK_METHOD(int, getBankStatement, (Bank&), (override));
    MOCK_METHOD(int, showBalance, (Bank&), (override));
    MOCK_METHOD(bool, logout, (), (override));
};

#endif
