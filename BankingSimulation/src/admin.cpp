#include "admin.h"
#include "constants.h"

Admin::Admin()
{
}

Admin::Admin(int aId, int adminPwd)
{
    adminId = aId;
    adminPassword = adminPwd;
}

int Admin::adminLogin()
{
    std::cout << "Enter your Login Id" << std::endl;
    std::cin >> adminId;
    std::cout << "Enter you password" << std::endl;
    std::cin >> adminPassword;

    // Since extern is used it will be declared in constants.h and can be defined anywhere in the files
    Admin adminData(101, 123456);

    return (adminId == adminData.adminId && adminPassword == adminData.adminPassword);
    
}

int Admin::createAccount()
{
    std::cout << "Enter Account Holder Details" << std::endl;

    Account newAccount;
    std::cout << "Name" << std::endl;
    std::cin >> newAccount.holderName;
    std::cout << "Address" << std::endl;
    std::cin >> newAccount.holderAddress;
    std::cout << "Contact" << std::endl;
    std::cin >> newAccount.holderContact;

    newAccount.accountNumber++;
    newAccount.totalBalance = 0;

    accountHolderData.push_back(newAccount);

    std::cout << "Account created successfully." << std::endl;
    std::cout << "Your account number is " << newAccount.accountNumber << std::endl;
    return 0;
}

void Admin::showOperationChoices()
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
    std::cout << "9.Logout" << std::endl;
}

void Admin::performOperation(int operationChoice)
{
    switch (operationChoice)
    {
    case 1:
        createAccount();
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
            // account.accountNumber = NULL;
            std::cout << "Account closed successfully" << std::endl;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return 0;
}

bool Admin::logout()
{
    std::cout << "Want to exit.\nPress q to quit.\nPress c to continue" << std::endl;
    char continueChoice;
    std::cin >> continueChoice;
    return (continueChoice == 'c') ? true : false;
}