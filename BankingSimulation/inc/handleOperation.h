#ifndef HANDLE_OPERATION_H
#define HANDLE_OPERATION_H

#include <iostream>
#include "bank.h"
#include "admin.h"
#include "accountHolder.h"

class HandleOperation
{
    int operationChoice;

public:
    int getOperationChoice();

    void setOperationChoice();

    void showAdminChoices();

    void showAccountHolderChoices();

    void performAdminOperation(BankUser &, Bank &);

    void performAccountHolderOperation(BankUser &, Bank &);
};

#endif