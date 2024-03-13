#include<gtest/gtest.h>
#include<iostream>
#include"mockBankServer.h"
#include"atmMachine.cpp"


TEST(AtmMachine,canWithdarw){
    const int accNumber=1234;
    const int withdraw_value=1000;

    MockBankServer bankServer;

    



    AtmMachine atm_machine(&bankServer);

    bool withdraw_result=atm_machine.Withdraw(1234,1000);

    EXPECT_FALSE(withdraw_result);
}