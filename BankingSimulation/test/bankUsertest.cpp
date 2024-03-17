#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "bankUser.h"
#include "bank.h"
#include "account.h"
#include "transaction.h"
#include "mockInputValidator.h"
#include "mockBank.h"
using ::testing::_;
using ::testing::Return;

class BankUserTest : public ::testing::Test
{
public:
    MockBank bankData;
    Account account;
    Transaction transaction;
    BankUser bankUser;
    MockInputValidator inputValidator;
};

TEST_F(BankUserTest, WithdrawMoney_ValidAccount_InSufficientBalance)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20);
    bankData.accountHolderData.push_back(account);

    EXPECT_CALL(inputValidator, isValidInput(::testing::_)).WillRepeatedly(::testing::Return(true));

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;
    inputBuffer << "100.0" << std::endl;

    ASSERT_FALSE(bankUser.withdrawMoney(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, WithdrawMoney_ValidAccount_SufficientBalance)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    EXPECT_CALL(inputValidator, isValidInput(::testing::_)).WillRepeatedly(::testing::Return(true));

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;
    inputBuffer << "100.0" << std::endl;

    ASSERT_TRUE(bankUser.withdrawMoney(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, WithdrawMoney_InvalidAccount)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    EXPECT_CALL(inputValidator, isValidInput(::testing::_)).WillRepeatedly(::testing::Return(false));

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4000" << std::endl;
    inputBuffer << "100.0" << std::endl;

    ASSERT_FALSE(bankUser.withdrawMoney(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, DepositMoney_ValidAccount)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;
    inputBuffer << "100.0" << std::endl;

    ASSERT_TRUE(bankUser.depositMoney(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, DepositMoney_InValidAccount)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "99999" << std::endl;
    inputBuffer << "100.0" << std::endl;

    ASSERT_FALSE(bankUser.depositMoney(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, FindStatement_Successful)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setTransactionType("Withdraw");
    transaction.setNetBalance(19950);
    bankData.transactionDetails.push_back(transaction);

    int accountNumber = 4001;

    ASSERT_TRUE(bankUser.findStatement(bankData, transaction, accountNumber));
}

TEST_F(BankUserTest, FindStatement_AcccountNotFound)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setTransactionType("Withdraw");
    transaction.setNetBalance(19950);
    bankData.transactionDetails.push_back(transaction);

    int accountNumber = 99999;

    ASSERT_FALSE(bankUser.findStatement(bankData, transaction, accountNumber));
}

TEST_F(BankUserTest, GetMiniBankStatement_WithTransactions)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setTransactionType("Withdraw");
    transaction.setNetBalance(19950);
    bankData.transactionDetails.push_back(transaction);

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;

    ASSERT_TRUE(bankUser.getMiniBankStatement(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, GetMiniBankStatement_NoTransactions)
{
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;

    ASSERT_FALSE(bankUser.getMiniBankStatement(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, GetBankStatement_WithTransactions)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    transaction.setAccountNumber(4001);
    transaction.setTransactionId(1);
    transaction.setTransactionAmount(50);
    transaction.setTransactionType("Withdraw");
    transaction.setNetBalance(19950);
    bankData.transactionDetails.push_back(transaction);

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;

    ASSERT_TRUE(bankUser.getBankStatement(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, GetBankStatement_NoTransactions)
{
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;

    ASSERT_FALSE(bankUser.getBankStatement(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, ShowBalance_ValidAccount)
{
    account.setAccountNumber(4001);
    account.setHolderName("dhairya");
    account.setHolderAddress("area1");
    account.setHolderContact(123456);
    account.setTotalBalance(20000);
    bankData.accountHolderData.push_back(account);

    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "4001" << std::endl;

    ASSERT_TRUE(bankUser.showBalance(bankData));

    std::cin.rdbuf(oldCin);
}

TEST_F(BankUserTest, ShowBalance_InvalidAccount)
{
    std::stringstream inputBuffer;
    std::streambuf *oldCin = std::cin.rdbuf(inputBuffer.rdbuf());
    inputBuffer << "99999" << std::endl;

    ASSERT_FALSE(bankUser.showBalance(bankData));

    std::cin.rdbuf(oldCin);
}
