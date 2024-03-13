#include<iostream>
#include<gtest/gtest.h>

bool isEqual(int a, int b){
    if(a==b)return true;
    else return false;
}

TEST(SampleTest, EqualTest){
    int a=1;
    int b=1;
    EXPECT_TRUE(isEqual(a,b));
    EXPECT_PRED2(isEqual,a,b);
}

int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}