#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "bankUser.h"
#include "Accounts.h"

class Admin : public BankUser
{
private:
    Accounts *bankData;
    int adminId{};
    int adminPassword{};

public:
    bool isLoggedIn{false};

    Admin(Accounts *bank) : bankData(bank) {}

    Admin(int, int);

    void adminLogin();

    int createAccount();

    void showUserList();

    void showParticularUser();

    int withdrawMoney();

    int depositMoney();

    bool printStatement(Account &,int );

    int getMiniBankStatement();

    int getBankStatement();

    int showBalance();

    int closeAccount();

    bool login();

    bool logout();

    // ~Admin(){}
};

#endif