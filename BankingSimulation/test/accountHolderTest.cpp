#include "accountHolder.h"
#include "mockInputValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class AccountHolderTest : public ::testing::Test
{
public:
    AccountHolder accountHolder;
    MockInputValidator inputValidator;
};

TEST_F(AccountHolderTest, Logout_Yes)
{

    EXPECT_CALL(inputValidator, isValidInput(::testing::_)).WillRepeatedly(::testing::Return(true));

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "y" << std::endl;

    bool result = accountHolder.logout();

    std::cin.rdbuf(oldCin);

    ASSERT_TRUE(result);
}

TEST_F(AccountHolderTest, Logout_No)
{
    AccountHolder accountHolder;

    MockInputValidator inputValidator;

    EXPECT_CALL(inputValidator, isValidInput(::testing::_)).WillRepeatedly(::testing::Return(true));

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "n" << std::endl;

    bool result = accountHolder.logout();

    std::cin.rdbuf(oldCin);

    ASSERT_FALSE(result);
}
