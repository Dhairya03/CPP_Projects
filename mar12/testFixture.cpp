#include <iostream>
#include <gtest/gtest.h>
class Base
{
    int value;

public:
    Base(int val)
    {
        value = val;
    }
    void increment(int inc)
    {
        value += inc;
    }
    int getValue()
    {
        return value;
    }
};

struct BaseTest : public testing::Test
{
    Base *b;
    void SetUp()
    {
        b = new Base(4);
    }
    void TearDown()
    {
        delete b;
    }
};

TEST_F(BaseTest, Test1)
{
    std::cout << "ancd" << std::endl;
    b->increment(5);
    std::cout << "ancd" << std::endl;
    ASSERT_EQ(b->getValue(), 9);
    std::cout << "Fixture Increment done value is" << b->getValue();
}

TEST(SampleTest, Test1)
{
    Base b(4);
    b.increment(5);
    ASSERT_EQ(b.getValue(), 9);
    std::cout << "Increment done value is" << b.getValue();
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}