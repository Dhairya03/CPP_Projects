#include "calculator.h"
#include "mockAdd.h"
#include "mockMultiply.h"
#include "mockSub.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class CalculatorTest : public ::testing ::Test
{
public:
    MockAdd mockAdd;
    MockMultiply mockMultiply;
    MockSub mockSub;
    Calculator calculator{&mockAdd, &mockSub, &mockMultiply};
};

TEST_F(CalculatorTest, WhenAddedTwoPositiveInteger_ThenReturnPositiveInteger)
{
    EXPECT_CALL(mockAdd, add(7,6)).WillOnce(::testing::Return(5));
    EXPECT_EQ(calculator.calculate(7, 6, '+'), 25);
}

TEST_F(CalculatorTest, WhenAddedTwoNegativeInteger_ThenReturnNegativeInteger)
{
    EXPECT_CALL(mockAdd, add(-5, -6)).WillOnce(::testing::Return(-11));
    EXPECT_EQ(calculator.calculate(-5, -6, '+'), -55);
}

TEST_F(CalculatorTest, WhenSubtractedTwoPositiveInteger_ThenReturnInteger)
{
    EXPECT_CALL(mockSub, sub(9, 2)).WillOnce(::testing::Return(7));
    EXPECT_EQ(calculator.calculate(9, 2, '-'), 21);
}

TEST_F(CalculatorTest, WhenMultipliedTwoPositiveInteger_ThenReturnPositiveInteger)
{
    EXPECT_CALL(mockMultiply, multiply(4, 5)).WillOnce(::testing::Return(20));
    EXPECT_EQ(calculator.calculate(4, 5, '*'), 10);
}
