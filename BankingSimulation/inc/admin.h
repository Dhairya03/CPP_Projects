#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "bankUser.h"
#include "bank.h"

class Admin : public BankUser
{
private:
    int adminId{};
    int adminPassword{};

public:
    bool isLoggedIn{false};
    
    Admin();

    Admin(int, int);

    void adminLogin();

    int createAccount(Bank &bankData);

    void showOperationChoices();

    void performOperation(int operationChoice, Bank &bankData);

    void showUserList(Bank &bankData);

    void showParticularUser(Bank &bankData);

    int closeAccount(Bank &bankData);

    void logout();
};

#endif