#include "transaction.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class TransactionTest : public ::testing::Test
{
public:
    Transaction transaction;
};

TEST_F(TransactionTest, GetAccountNumber)
{
    int accountNumber = 12345;
    transaction.setAccountNumber(accountNumber);
    EXPECT_EQ(transaction.getAccountNumber(), accountNumber);
}

TEST_F(TransactionTest, GetTransactionId)
{
    int transactionId = 1001;
    transaction.setTransactionId(transactionId);
    EXPECT_EQ(transaction.getTransactionId(), transactionId);
}

TEST_F(TransactionTest, GetTransactionAmount)
{
    double transactionAmount = 500.0;
    transaction.setTransactionAmount(transactionAmount);
    EXPECT_EQ(transaction.getTransactionAmount(), transactionAmount);
}

TEST_F(TransactionTest, GetNetBalance)
{
    double netBalance = 2500.0;
    transaction.setNetBalance(netBalance);
    EXPECT_EQ(transaction.getNetBalance(), netBalance);
}

TEST_F(TransactionTest, GetTransactionType)
{
    std::string transactionType = "Withdraw";
    transaction.setTransactionType(transactionType);
    EXPECT_EQ(transaction.getTransactionType(), transactionType);
}

TEST_F(TransactionTest, SetAccountNumber)
{
    int accountNumber = 123456;
    transaction.setAccountNumber(accountNumber);
    EXPECT_EQ(transaction.getAccountNumber(), accountNumber);
}

TEST_F(TransactionTest, SetTransactionId)
{
    int transactionId = 1001;
    transaction.setTransactionId(transactionId);
    EXPECT_EQ(transaction.getTransactionId(), transactionId);
}

TEST_F(TransactionTest, SetTransactionAmount)
{
    double transactionAmount = 500.0;
    transaction.setTransactionAmount(transactionAmount);
    EXPECT_EQ(transaction.getTransactionAmount(), transactionAmount);
}

TEST_F(TransactionTest, SetNetBalance)
{
    double netBalance = 2500.0;
    transaction.setNetBalance(netBalance);
    EXPECT_EQ(transaction.getNetBalance(), netBalance);
}

TEST_F(TransactionTest, SetTransactionType)
{
    std::string transactionType = "Withdraw";
    transaction.setTransactionType(transactionType);
    EXPECT_EQ(transaction.getTransactionType(), transactionType);
}
