#include<iostream>
#include<gtest/gtest.h>

TEST(SampleTest,Test1){
    ASSERT_EQ(1,1);
    std::cout<<"Assertion Successfull"<<std::endl;
}

TEST(SampleTest,Test2){
    ASSERT_EQ(1,2);
    std::cout<<"Assertion Successfull"<<std::endl;
}
TEST(SampleTest,Test3){
    EXPECT_EQ(1,1);
    std::cout<<"Expectation Successfull"<<std::endl;
}

TEST(SampleTest,Test4){
    EXPECT_EQ(1,2);
    std::cout<<"Expectation Successfull"<<std::endl;
}

int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}