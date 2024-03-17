#include "account.h"
#include "account.cpp"
#include <gtest/gtest.h>

class AccountTest : public ::testing::Test
{
public:
    Account *account;
    void SetUp()
    {
        account = new Account();
    }
    void TearDown()
    {
        delete account;
    }
};

TEST_F(AccountTest,getAccountNumberSuccessTest){
    const int accountNumber=4001;
    account->setAccountNumber(accountNumber);
    EXPECT_EQ(account->getAccountNumber(),accountNumber);
}

TEST_F(AccountTest,getAccountNumberFailureTest){
    const int accountNumber=3000;
    account->setAccountNumber(accountNumber);
    EXPECT_EQ(account->getAccountNumber(),accountNumber);
}