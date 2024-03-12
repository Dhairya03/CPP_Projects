#include<iostream>
#include<gtest/gtest.h>

class Base{
    std::string str;
    public:
    Base(std::string input):str(input){}
    std::string getString(){
        std::cout<<str<<std::endl;
        return str;
    }
};

TEST(SampleTest,EqualString){
    Base b("dhairya");
    std::string str=b.getString();
    ASSERT_EQ(str,"dhairya");
}

int main(int argc,char** argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}