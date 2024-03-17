#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mockBankUser.h"
#include "bankUser.h"
#include "bank.h"
#include "account.h"
#include "transaction.h"
using ::testing::_;
using ::testing::Return;

class BankUserTest : public ::testing::Test
{
public:
    Bank bankData;
    Account account;
    Transaction transaction;
    MockBankUser mockBankUser;
    void SetUp(){

    }
};

TEST_F(BankUserTest, LoginTestSuccess)
{
    EXPECT_CALL(mockBankUser, login()).Times(1).WillOnce(Return(true));

    bool result = mockBankUser.login();

    ASSERT_TRUE(result);
}

TEST_F(BankUserTest, LoginTestFailure)
{
    EXPECT_CALL(mockBankUser, login()).Times(1).WillOnce(Return(false));

    bool result = mockBankUser.login();

    ASSERT_FALSE(result);
}

TEST_F(BankUserTest, WithdrawalSuccess)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    EXPECT_CALL(mockBankUser, withdrawMoney(_)).Times(1).WillOnce(Return(1));

    int result = mockBankUser.withdrawMoney(bankData);

    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setNetBalance(19950);
    transaction.setTransactionType("Withdraw");

    bankData.transactionDetails.push_back(transaction);

    EXPECT_EQ(transaction.getNetBalance(), account.getTotalBalance() - transaction.getTransactionAmount());
    ASSERT_EQ(result, 1);
}

TEST_F(BankUserTest, WithdrawalFailure)
{

    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    EXPECT_CALL(mockBankUser, withdrawMoney(_)).Times(1).WillOnce(Return(0));

    int result = mockBankUser.withdrawMoney(bankData);
    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setNetBalance(19000);
    transaction.setTransactionType("Withdraw");

    bankData.transactionDetails.push_back(transaction);

    EXPECT_NE(transaction.getNetBalance(), account.getTotalBalance() - transaction.getTransactionAmount());
    ASSERT_EQ(result, 0);
}

TEST_F(BankUserTest, DepositSuccess)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    EXPECT_CALL(mockBankUser, withdrawMoney(_)).Times(1).WillOnce(Return(1));

    int result = mockBankUser.withdrawMoney(bankData);

    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setNetBalance(20050);
    transaction.setTransactionType("Deposit");

    bankData.transactionDetails.push_back(transaction);

    EXPECT_EQ(transaction.getNetBalance(), account.getTotalBalance() + transaction.getTransactionAmount());
    ASSERT_EQ(result, 1);
}

TEST_F(BankUserTest, DepositFailure)
{

    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    EXPECT_CALL(mockBankUser, withdrawMoney(_)).Times(1).WillOnce(Return(0));

    int result = mockBankUser.withdrawMoney(bankData);
    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setNetBalance(19000);
    transaction.setTransactionType("Deposit");

    bankData.transactionDetails.push_back(transaction);

    EXPECT_NE(transaction.getNetBalance(), account.getTotalBalance() + transaction.getTransactionAmount());
    ASSERT_EQ(result, 0);
}