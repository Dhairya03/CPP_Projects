#include "transaction.h"
#include "transaction.cpp"
#include "gmock/gmock.h"
#include "gtest/gtest.h"

class TransactionTest : public ::testing::Test
{
public:
    Transaction *trans;

    void SetUp()
    {
        trans = new Transaction;
    }
    void TearDown()
    {
        delete trans;
    }
};

TEST_F(TransactionTest, getAccountTest)
{
    const int accountNumber = 4001;
    trans->setAccountNumber(4001);
    EXPECT_THAT(trans->getAccountNumber(), accountNumber);
    EXPECT_NE(trans->getAccountNumber(), accountNumber - 1);
}

TEST_F(TransactionTest, getTransactionIdTest)
{
    trans->setTransactionId(4);
    EXPECT_THAT(trans->getTransactionId(), 4);
    EXPECT_NE(trans->getTransactionId(), 0);
    EXPECT_NE(trans->getTransactionId(), -1);
}

TEST_F(TransactionTest, getTransactionAmountTest)
{
    trans->setTransactionAmount(400);
    trans->setNetBalance(4000);
    EXPECT_THAT(trans->getTransactionAmount(), 400);
    EXPECT_NE(trans->getTransactionAmount(), -1);
    EXPECT_LT(trans->getTransactionAmount(), trans->getNetBalance());
}

TEST_F(TransactionTest, getNetBalanceTest)
{
    trans->setNetBalance(4000);
    EXPECT_THAT(trans->getNetBalance(), 4000);
    EXPECT_GT(trans->getNetBalance(), -1);
}

TEST_F(TransactionTest, getTransactionTypeTest)
{
    trans->setTransactionType("Withdraw");
    EXPECT_THAT(trans->getTransactionType(), "Withdraw");
    EXPECT_NE(trans->getTransactionType(), "random");
    trans->setTransactionType("Deposit");
    EXPECT_THAT(trans->getTransactionType(), "Deposit");
    EXPECT_NE(trans->getTransactionType(), "random");
}