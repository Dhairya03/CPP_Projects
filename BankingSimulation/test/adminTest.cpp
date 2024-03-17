#include "admin.h"
#include "mockBankUser.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

// class AdminTest : public ::testing::Test
// {
//     BankUser *b;

// public:
//     AdminTest(BankUser *bankUser) : b(bankUser) {}
//     void SetUp() {
//         MockBankUser *mb;
//         mb->init();
//     }
//     int withdraw(Bank &bankData)
//     {
//         int result = 0;
//         b->login();
//         int value;
//         std::cin >> value;
//         // b->withdrawMoney(bankData);

//         auto available_balance = b->showBalance(bankData);

//         if (available_balance >= value)
//         {

//             b->withdrawMoney(bankData);

//             result = true;
//         }

//         b->logout();

//         return result;
//     }
// };
class BankUserTest : public ::testing::Test {
protected:
    MockBankUser mockBankUser;
};

TEST_F(BankUserTest, LoginTest) {
    // Set up expectations
    EXPECT_CALL(mockBankUser, login()).Times(1).WillOnce(::testing::Return(true));

    // Call the function under test
    bool result = mockBankUser.login();

    // Assert the result
    ASSERT_TRUE(result);
}
// TEST(Admin_Test, WithdrawalSuccess)
// {
//     MockBankUser *mb;
//     Bank bankData;
//     Account account;
//     account.setAccountNumber(4001);
//     account.setHolderName("dhairya");
//     account.setHolderAddress("area1");
//     account.setHolderContact(123456);
//     account.setTotalBalance(40000);

//     bankData.accountHolderData.push_back(account);

//     Transaction transaction;
//     bankData.transactionDetails.push_back(transaction);

//     EXPECT_CALL(*mb,withdrawMoney(bankData))
//     .Times(1);
//     AdminTest *admin;
//     int returnValue=admin->withdraw(bankData);
//     EXPECT_EQ(returnValue,1);
    
// }