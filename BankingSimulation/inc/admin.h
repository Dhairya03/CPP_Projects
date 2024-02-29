#ifndef ADMIN_H
#define ADMIN_H

#include <iostream>

#include "bank.h"

class Admin : public Bank
{
public:
    int adminId{};
    int adminPassword{};

public:
    Admin();

    Admin(int,int);

    int adminLogin();

    int createAccount();

    void showOperationChoices();

    void performOperation(int operationChoice);

    void seeUserList();

    void seeParticularUser();

    int closeAccount();

    bool logout();

};

#endif