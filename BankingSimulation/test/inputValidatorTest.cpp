#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "inputValidator.h"

class InputValidatorTest : public ::testing::Test
{
public:
    InputValidator inputValidator;
};

TEST_F(InputValidatorTest, SetValidUserChoice)
{
    EXPECT_TRUE(inputValidator.setUserChoice(4));
    EXPECT_EQ(4,inputValidator.getUserChoice());
}
TEST_F(InputValidatorTest, SetInValidUserChoice)
{
    EXPECT_FALSE(inputValidator.setUserChoice(-1));
    EXPECT_EQ(-1,inputValidator.getUserChoice());
}

TEST_F(InputValidatorTest, GetValidUserChoice)
{
    inputValidator.setUserChoice(2);
    EXPECT_EQ(inputValidator.getUserChoice(),2);
}

TEST_F(InputValidatorTest, GetInValidUserChoice)
{
    inputValidator.setUserChoice(-1);
    EXPECT_GT(inputValidator.getUserChoice(), 0);
}