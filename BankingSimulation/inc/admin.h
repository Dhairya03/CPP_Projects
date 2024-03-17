#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>
#include "bankUser.h"
#include "bank.h"
#include "IAdmin.h"

class Admin : public BankUser
{
private:
    int adminId{};
    int adminPassword{};

public:
    bool isLoggedIn{false};

    Admin();

    Admin(int, int);

    bool login();

    void createAccount(Bank &bankData);

    bool showUserList(Bank &bankData);

    bool showParticularUser(Bank &bankData);

    int closeAccount(Bank &bankData);

    bool logout();
};

#endif