#include <iostream>
#include <gtest/gtest.h>

int factorial(int n)
{
    if (n < 0)
        return -1;
    else if (n == 0 || n == 1)
        return 1;

    else
    {
        return n * factorial(n - 1);
    }
}

TEST(FactorialTest, isZero)
{
    EXPECT_EQ(1, factorial(0));
}

TEST(FactorialTest, isPositive)
{
    ASSERT_NE(1,factorial(1));
    EXPECT_EQ(2,factorial(2));
    EXPECT_EQ(6,factorial(3));
    EXPECT_NE(250,factorial(5));
}

// int main(int argc, char **argv)
// {
//     ::testing::InitGoogleTest(&argc, argv);

//     return RUN_ALL_TESTS();
// }