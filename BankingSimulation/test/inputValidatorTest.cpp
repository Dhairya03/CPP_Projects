#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "inputValidator.h"

class InputValidatorTest : public ::testing::Test
{
protected:
    InputValidator inputValidator;
};

TEST_F(InputValidatorTest, SetUserChoiceValidInput)
{
    int userChoice = 1;

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "1" << std::endl; 

    inputValidator.setUserChoice();

    EXPECT_EQ(inputValidator.getUserChoice(), userChoice);
}

TEST_F(InputValidatorTest, SetUserChoiceInvalidInput)
{
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "0" << std::endl; 

    inputValidator.setUserChoice();

    EXPECT_NE(inputValidator.getUserChoice(), 1); 
}
