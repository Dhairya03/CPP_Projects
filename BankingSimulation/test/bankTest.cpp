#include "mockBank.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

TEST(BankTest, GetAccountHolderData) {
    MockBank mockBank;
    std::vector<Account> mockAccountHolderData = {};

    EXPECT_CALL(mockBank, getAccountHolderData())
        .WillOnce(::testing::ReturnRef(mockAccountHolderData));


}

TEST(BankTest, GetTransactionDetails) {
    MockBank mockBank;
    std::vector<Transaction> mockTransactionDetails = {};

    EXPECT_CALL(mockBank, getTransactionDetails())
        .WillOnce(::testing::ReturnRef(mockTransactionDetails));

}