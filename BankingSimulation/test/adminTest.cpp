#include "admin.h"
#include "mockBank.h"
#include "mockInputValidator.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class AdminTest : public ::testing::Test
{
public:
    Admin admin;
    MockInputValidator inputValidator;
    MockBank bankData;
};

TEST_F(AdminTest, Login_Successful)
{

    EXPECT_CALL(inputValidator, isValidInput(::testing::_)).WillRepeatedly(::testing::Return(true));

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "101" << std::endl;
    inputBuffer << "123456" << std::endl;

    std::cin.rdbuf(oldCin);

    ASSERT_TRUE(admin.login());
}

TEST_F(AdminTest, Login_Unsuccessful)
{
    EXPECT_CALL(inputValidator, isValidInput(::testing::_)).WillRepeatedly(::testing::Return(true));

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "123" << std::endl;
    inputBuffer << "223434" << std::endl;

    std::cin.rdbuf(oldCin);

    ASSERT_FALSE(admin.login());
}

TEST_F(AdminTest, CreateAccount_Successful)
{
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "dhairya" << std::endl;
    inputBuffer << "area1" << std::endl;
    inputBuffer << "12345" << std::endl;

    admin.createAccount(bankData);

    std::cin.rdbuf(oldCin);
}

TEST_F(AdminTest, ShowUserList_WithUsers)
{
    Account account;
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(40000);

    bankData.accountHolderData.push_back(account);

    std::stringstream outputStream;
    std::streambuf *oldCout = std::cout.rdbuf(outputStream.rdbuf());

    std::cout.rdbuf(oldCout);

    ASSERT_TRUE(admin.showUserList(bankData));
}

TEST_F(AdminTest, ShowUserList_NoUsers)
{
    std::stringstream outputStream;
    std::streambuf *oldCout = std::cout.rdbuf(outputStream.rdbuf());

    std::cout.rdbuf(oldCout);

    ASSERT_FALSE(admin.showUserList(bankData));
}

TEST_F(AdminTest, ShowParticularUser_ExistingUser)
{
    Account account;
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(40000);

    bankData.accountHolderData.push_back(account);

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;

    std::stringstream outputStream;
    std::streambuf *oldCout = std::cout.rdbuf(outputStream.rdbuf());

    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    ASSERT_TRUE(admin.showParticularUser(bankData));
}

TEST_F(AdminTest, ShowParticularUser_NonExistingUser)
{
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "99999" << std::endl; 

    std::stringstream outputStream;
    std::streambuf *oldCout = std::cout.rdbuf(outputStream.rdbuf());

    std::cin.rdbuf(oldCin);
    std::cout.rdbuf(oldCout);

    ASSERT_FALSE(admin.showParticularUser(bankData));
}

TEST_F(AdminTest, CloseAccount_ExistingAccount)
{
    Account account;
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(40000);

    bankData.accountHolderData.push_back(account);

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl; 

    ASSERT_TRUE(admin.closeAccount(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(AdminTest, CloseAccount_NonExistingAccount)
{
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "99999" << std::endl; 

    ASSERT_FALSE(admin.closeAccount(bankData));

    std::cin.rdbuf(oldCin);

}

TEST_F(AdminTest, Logout_YesChoice)
{
    admin.login();
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "y" << std::endl;

    std::cin.rdbuf(oldCin);

    ASSERT_FALSE(admin.logout()); 
}

TEST_F(AdminTest, Logout_NoChoice)
{
    admin.login();
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "n" << std::endl; 

    std::cin.rdbuf(oldCin);

    ASSERT_TRUE(admin.logout()); 
}
