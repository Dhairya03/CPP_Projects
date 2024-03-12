#include<iostream>
#include<gtest/gtest.h>

TEST(SampleTest,Add){
    int numOne=3;
    int numTwo=5;
    int result=numOne+numTwo;

    ASSERT_EQ(result,8);
    std::cout<<"Addition done Sum is "<<result;
}

//All test are independent of each other same variable name also does not depend 

TEST(SampleTest,Subtract){
    int numOne=3;
    int numTwo=5;
    int result=numOne-numTwo;

    ASSERT_EQ(result,-2);
    std::cout<<"Subtraction done Result is "<<result;
}

int main(int argc, char**argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}