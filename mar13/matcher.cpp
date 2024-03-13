#include<iostream>
#include<gtest/gtest.h>
#include<gmock/gmock.h>

TEST(SampleMatcherTest, Test1){
    ::testing::Matcher<int>is_one=1;
    ::testing::Matcher<int>is_two=2;
    ::testing::Matcher<bool>is_True=true;

    EXPECT_THAT(1,is_one);
    EXPECT_THAT(2,is_two);
    EXPECT_THAT(true,is_True);
}

int main(int argc, char** argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}