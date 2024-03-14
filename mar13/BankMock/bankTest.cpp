#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <iostream>
#include "mockBankServer.h"
#include "atmMachine.cpp"

using ::testing::Return;

TEST(Atm_Machine, onCallWithOneFunctionSpecified)
{
    const int accNumber = 1234;
    const int withdraw_value = 1000;

    MockBankServer bankServer;

    ON_CALL(bankServer, Connect).WillByDefault(Return());

    ON_CALL(bankServer, GetBalance(accNumber)).WillByDefault(Return(2000));

    ON_CALL(bankServer, Withdraw).WillByDefault(Return());

    ON_CALL(bankServer, Disconnect).WillByDefault(Return());

    ON_CALL(bankServer,Credit).WillByDefault(Return());

    AtmMachine atm_machine(&bankServer);

    bool withdraw_result1 = atm_machine.Withdraw(accNumber, withdraw_value);
    bool withdraw_result2 = atm_machine.Withdraw(accNumber + 1, withdraw_value);

    EXPECT_TRUE(withdraw_result1);
    EXPECT_FALSE(withdraw_result2);
}
