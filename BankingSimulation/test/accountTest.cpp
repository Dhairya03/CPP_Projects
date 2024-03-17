#include "account.h"
#include "account.cpp"
#include <gtest/gtest.h>

class AccountTest : public ::testing::Test
{
protected:
    Account account;
};

TEST_F(AccountTest, GetAccountNumber)
{
    int accountNumber = 4001;
    account.setAccountNumber(accountNumber);
    EXPECT_EQ(account.getAccountNumber(), accountNumber);
}

TEST_F(AccountTest, GetHolderName)
{
    std::string holderName = "dhairya";
    account.setHolderName(holderName);
    EXPECT_EQ(account.getHolderName(), holderName);
}

TEST_F(AccountTest, GetHolderContact)
{
    long holderContact = 12345;
    account.setHolderContact(holderContact);
    EXPECT_EQ(account.getHolderContact(), holderContact);
}

TEST_F(AccountTest, GetHolderAddress)
{
    std::string holderAddress = "area1";
    account.setHolderAddress(holderAddress);
    EXPECT_EQ(account.getHolderAddress(), holderAddress);
}

TEST_F(AccountTest, GetTotalBalance)
{
    double totalBalance = 1000;
    account.setTotalBalance(totalBalance);
    EXPECT_EQ(account.getTotalBalance(), totalBalance);
}
TEST_F(AccountTest, SetAccountNumber)
{
    int accountNumber = 4001;
    account.setAccountNumber(accountNumber);
    EXPECT_EQ(account.getAccountNumber(), accountNumber);
}

TEST_F(AccountTest, SetHolderName)
{
    std::string holderName = "dhairya";
    account.setHolderName(holderName);
    EXPECT_EQ(account.getHolderName(), holderName);
}

TEST_F(AccountTest, SetHolderContact)
{
    long holderContact = 12345;
    account.setHolderContact(holderContact);
    EXPECT_EQ(account.getHolderContact(), holderContact);
}

TEST_F(AccountTest, SetHolderAddress)
{
    std::string holderAddress = "Area1";
    account.setHolderAddress(holderAddress);
    EXPECT_EQ(account.getHolderAddress(), holderAddress);
}

TEST_F(AccountTest, SetTotalBalance)
{
    double initialBalance = 1000.0;
    double depositAmount = 500.0;
    account.setTotalBalance(initialBalance);
    account.setTotalBalance(depositAmount);
    EXPECT_EQ(account.getTotalBalance(), initialBalance + depositAmount);
}

