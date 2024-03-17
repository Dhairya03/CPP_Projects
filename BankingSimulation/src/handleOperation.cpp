#include "handleOperation.h"
#include "inputValidator.h"

int HandleOperation::getOperationChoice()
{
    return operationChoice;
}

void HandleOperation::setOperationChoice()
{
    InputValidator inputValidator;
    while (true)
    {
        std::cin >> operationChoice;
        if (inputValidator.isValidInput(operationChoice))
            break;
        else
            std::cout << "Enter Valid user choice" << std::endl;
    }
}

void HandleOperation::showAccountHolderChoices()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Withraw money from Account" << std::endl;
    std::cout << "2.Deposit money in Account" << std::endl;
    std::cout << "3.Get Mini Bank Statement" << std::endl;
    std::cout << "4.Get Bank Statement" << std::endl;
    std::cout << "5.Show Balance" << std::endl;
    std::cout << "6.EXIT" << std::endl;
}

void HandleOperation::showAdminChoices()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Create Account" << std::endl;
    std::cout << "2.See the list of Account Holders" << std::endl;
    std::cout << "3.See the account details of a particular Account Holder" << std::endl;
    std::cout << "4.Withraw money from Account" << std::endl;
    std::cout << "5.Deposit money in Account" << std::endl;
    std::cout << "6.Get Mini Bank Statement" << std::endl;
    std::cout << "7.Get Bank Statement" << std::endl;
    std::cout << "8.Show Balance" << std::endl;
    std::cout << "9.Close Account" << std::endl;
    std::cout << "10.Logout" << std::endl;
}

void HandleOperation::performAdminOperation(BankUser &admin, Bank &bankData)
{
    // std::cout<<getOperationChoice()<<std::endl;
    Admin *user=(Admin*)&admin;
    switch (getOperationChoice())
    {
    case 1:

        user->createAccount(bankData);
        break;

    case 2:
        user->showUserList(bankData);
        break;

    case 3:
        user->showParticularUser(bankData);
        break;

    case 4:
        admin.withdrawMoney(bankData);
        break;

    case 5:
        admin.depositMoney(bankData);
        break;

    case 6:
        admin.getMiniBankStatement(bankData);
        break;

    case 7:
        admin.getBankStatement(bankData);
        break;

    case 8:
        admin.showBalance(bankData);
        break;

    case 9:
        user->closeAccount(bankData);
        break;

    case 10:
        user->logout();
        break;

    default:
        std::cout << "You have selected invalid Operation to perform." << std::endl;
        break;
    }
}

void HandleOperation::performAccountHolderOperation(BankUser& accountHolder,Bank& bankData){
    AccountHolder*user=(AccountHolder*)&accountHolder;
    switch (getOperationChoice())
    {
    case 1:
        accountHolder.withdrawMoney(bankData);
        break;

    case 2:
        accountHolder.depositMoney(bankData);
        break;

    case 3:
       accountHolder.getMiniBankStatement(bankData);
        break;

    case 4:
        accountHolder.getBankStatement(bankData);
        break;

    case 5:
        accountHolder.showBalance(bankData);
        break;

    case 6:
        user->logout();
        break;

    default:
        std::cout << "You have selected invalid operation to perform." << std::endl;
        break;
    }
}