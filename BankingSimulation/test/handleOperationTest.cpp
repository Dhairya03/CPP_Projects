#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "mockAdmin.h"
#include "handleOperation.h"
#include "mockBank.h"
#include "mockInputValidator.h"
#include "mockAccountHolder.h"

class HandleOperationTest : public ::testing::Test
{
protected:
    MockAccountHolder mockAccountHolder;
    MockAdmin mockAdmin;
    MockBank mockBank;
    HandleOperation handleOperation;
    Admin admin;
    AccountHolder accountHolder;

    void SetUp()
    {
        Account account;
        account.setAccountNumber(4001);
        account.setHolderName("dhairya");
        account.setHolderAddress("area1");
        account.setHolderContact(123456);
        account.setTotalBalance(40000);

        mockBank.accountHolderData.push_back(account);
    }
};

TEST_F(HandleOperationTest, GetOperationChoice){
    int operationChoice=1;
    handleOperation.setOperationChoice();
    EXPECT_EQ(handleOperation.getOperationChoice(), operationChoice);
}

TEST_F(HandleOperationTest, SetOperationChoice)
{
    int operationChoice = 1;

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "1" << std::endl; 

    handleOperation.setOperationChoice();

    EXPECT_EQ(handleOperation.getOperationChoice(), operationChoice);

    std::cin.rdbuf(oldCin);
}