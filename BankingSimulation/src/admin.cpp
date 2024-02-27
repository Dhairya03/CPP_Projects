#include "admin.h"
#include "constants.cpp"

Admin::Admin()
{
}

Admin::Admin(int adminId,int adminPwd){
    adminId=adminId;
    adminPassword=adminPwd;
}

int Admin::adminLogin()
{
    std::cout << "Enter your Login Id" << std::endl;
    std::cin >> adminId;
    if (adminId == adminData.adminId)
    {
        std::cout << "Enter you password" << std::endl;
        std::cin >> adminPassword;
        if (adminPassword == adminData.adminPassword)
        {
            std::cout << "Successfully login" << std::endl;
        }
        else
        {
            std::cout << "Wrong Password!!" << std::endl;
        }
    }
    else
    {
        std::cout << "Wrong login id!!" << std::endl;
    }
}

void Admin::showOperationChoices()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Admin Login" << std::endl;
    std::cout << "2.See the list of Account Holders" << std::endl;
    std::cout << "3.See the account details of a particular Account Holder" << std::endl;
    std::cout << "4.Withraw money from Account" << std::endl;
    std::cout << "5.Deposit money in Account" << std::endl;
    std::cout << "6.Get Mini Bank Statement" << std::endl;
    std::cout << "7.Get Bank Statement" << std::endl;
    std::cout << "8.Show Balance" << std::endl;
    std::cout << "9.EXIT" << std::endl;
}

void Admin::performOperation(int operationChoice)
{
    switch (operationChoice)
    {
    case 1:
        break;

    case 2:
        seeUserList();
        break;
    case 3:
        seeParticularUser();
        break;
    case 4:
        withdrawMoney();
        break;
    case 5:
        depositMoney();
        break;
    case 6:
        getMiniBankStatement();
        break;
    case 7:
        getBankStatement();
        break;
    case 8:
        showBalance();
        break;
    case 9:
        break;

    default:
        std::cout << "You have selected invalid Operation to perform." << std::endl;
        break;
    }
}

void Admin::seeUserList()
{
    std::cout << "User List is" << std::endl;
    for (auto &account : accountHolderData)
    {
        std::cout << account.accountNumber << " " << account.holderName << " " << account.totalBalance << std::endl;
    }
}

void Admin::seeParticularUser()
{
    int accountNumber;
    std::cout << "Enter account Number of which you want to see details" << std::endl;
    std::cout << "Requested User is" << std::endl;
    for (auto &account : accountHolderData)
    {
        if (accountNumber == account.accountNumber)
        {
            std::cout << account.accountNumber << " " << account.holderName << " " << account.holderAddress << " " << account.holderContact << " " << account.totalBalance << std::endl;
        }
    }
}

int Admin::closeAccount()
{
    int accountNumber;
    std::cout << "Enter Account Number to close: ";
    std::cin >> accountNumber;

    bool found = false;
    for (auto &account : accountHolderData)
    {
        if (account.accountNumber == accountNumber)
        {
            found = true;
            account.accountNumber = NULL;
            std::cout << "Account closed successfully" << std::endl;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
}