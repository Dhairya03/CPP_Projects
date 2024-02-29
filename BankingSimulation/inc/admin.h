#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

#include "bank.h"

class Admin : public Bank
{
public:
    int adminId{};
    int adminPassword{};
    bool isLoggedIn{false};

public:
    Admin();

    Admin(int,int);

    void adminLogin();

    int createAccount(Bank &b);

    void showOperationChoices();

    void performOperation(int operationChoice, Bank&b);

    void seeUserList(Bank &b);

    void seeParticularUser(Bank &b);

    int closeAccount(Bank &b);

    void logout();

};

#endif