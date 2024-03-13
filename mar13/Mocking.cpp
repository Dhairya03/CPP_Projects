#include <iostream>
#include <gtest/gtest.h>
#include <gmock/gmock.h>

using ::testing::_;
using ::testing::AtLeast;
using ::testing::Return;

class DataBaseConnect
{
public:
    virtual bool login(std::string userName, std::string password)
    {
        return true;
    }
    virtual bool logout(std::string userName) { return true; }
    virtual int fetchRecord() { return -1; }
};

class MockDB : public DataBaseConnect
{
public:
    MOCK_METHOD0(fetchRecord, int());
    MOCK_METHOD1(logout, bool(std::string));
    MOCK_METHOD2(login, bool(std::string, std::string));
};

class MyDatabase
{
    DataBaseConnect &dbc;

public:
    MyDatabase(DataBaseConnect &_dbc) : dbc(_dbc) {}
    int Init(std::string userName, std::string password)
    {
        if (dbc.login(userName, password) != true)
        {
            std::cout << "DB Failure" << std::endl;
            return -1;
        }
        else
        {
            std::cout << "DB Success" << std::endl;
            return 1;
        }
    }
};

TEST(MyDBTest,LoginSuccess){
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb,login(_,_))
    .Times(1)
    .WillOnce(Return(true));

    int returnValue=db.Init("Dhairya","12345");

    EXPECT_EQ(returnValue,1);

}

TEST(MyDBTest,LoginFailure){
    MockDB mdb;
    MyDatabase db(mdb);

    EXPECT_CALL(mdb,login("Dhairya","123456"))
    .Times(1)
    .WillOnce(Return(false));

    int returnValue=db.Init("Dhairya","123456");

    EXPECT_EQ(returnValue,-1);

}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
