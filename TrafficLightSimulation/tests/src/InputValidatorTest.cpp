#include <gtest/gtest.h>
#include "inputValidator.h"

class InputValidatorTest : public ::testing::Test
{
public:
    InputValidator inputValidator;
};

TEST_F(InputValidatorTest, WhenGivenLaneIsValid_ThenIsValidLaneReturnTrue)
{
    int lane=1;
    EXPECT_TRUE(inputValidator.isValidLane(lane));
}

TEST_F(InputValidatorTest, WhenGivenLaneIsInvalid_ThenIsValidLaneReturnFalse)
{
    int lane=5;
    EXPECT_FALSE(inputValidator.isValidLane(lane));
}



