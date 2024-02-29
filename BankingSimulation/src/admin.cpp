#include "admin.h"
#include "constants.h"
#include "inputValidator.h"

// Since extern is used it will be declared in constants.h and can be defined anywhere in the files
Admin adminData(101, 123456);

Admin::Admin()
{
}

Admin::Admin(int aId, int adminPwd)
{
    adminId = aId;
    adminPassword = adminPwd;
}

void Admin::adminLogin()
{
    InputValidator input;
    std::cout << "Enter your Login Id" << std::endl;
    while (true)
    {
        std::cin >> adminId;
        if (input.isValidInput(adminId))
            break;
        else
            std::cout << "Invalid Id. Please enter again" << std::endl;
    }

    std::cout << "Enter you password" << std::endl;
    while (true)
    {
        std::cin >> adminPassword;
        if (input.isValidInput(adminPassword))
            break;
        else
            std::cout << "Invalid Password. Please enter again" << std::endl;
    }

    if (adminId == adminData.adminId && adminPassword == adminData.adminPassword)
    {
        std::cout << "Successful Login" << std::endl;
        isLoggedIn = true;
    }
    else
    {
        std::cout << "Invalid Credentials" << std::endl;
    }
}

int Admin::createAccount(Bank &bankData)
{
    std::cout << "Enter Account Holder Details" << std::endl;

    Account newAccount;
    std::cout << "Name" << std::endl;
    std::cin >> newAccount.holderName;
    std::cout << "Address" << std::endl;
    std::cin >> newAccount.holderAddress;
    std::cout << "Contact" << std::endl;
    std::cin >> newAccount.holderContact;

    newAccount.accountNumber += bankData.accountHolderData.size() + 1;
    
    newAccount.totalBalance = 0;

    bankData.accountHolderData.push_back(newAccount);

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
    std::cout << "9.Close Account" << std::endl;
    std::cout << "10.Logout" << std::endl;
}

void Admin::performOperation(int operationChoice, Bank &bankData)
{
    switch (operationChoice)
    {
    case 1:
        createAccount(bankData);
        break;

    case 2:
        seeUserList(bankData);
        break;

    case 3:
        seeParticularUser(bankData);
        break;

    case 4:
        withdrawMoney(bankData);
        break;

    case 5:
        depositMoney(bankData);
        break;

    case 6:
        getMiniBankStatement(bankData);
        break;

    case 7:
        getBankStatement(bankData);
        break;

    case 8:
        showBalance(bankData);
        break;

    case 9:
        closeAccount(bankData);
        break;

    case 10:
        logout();
        break;

    default:
        std::cout << "You have selected invalid Operation to perform." << std::endl;
        break;
    }
}

void Admin::seeUserList(Bank &bankData)
{
    std::cout << "User List is" << std::endl;
    std::cout << "Account NUmber"
              << " "
              << "Account Holder name"
              << " "
              << "Toatl balance" << std::endl;

    for (auto &account : bankData.accountHolderData)
    {
        std::cout << account.accountNumber << " " << account.holderName << " " << account.totalBalance << std::endl;
    }
}

void Admin::seeParticularUser(Bank &bankData)
{
    InputValidator input;
    int accountNumber;
    std::cout << "Enter account Number of which you want to see details" << std::endl;
    while (true)
    {
        std::cin >> accountNumber;
        if (input.isValidInput(accountNumber))
            break;
        else
            std::cout << "you have entered invalid account number.Enter valid account number" << std::endl;
    }
    std::cout << "Requested User is" << std::endl;
    std::cout << "Account Number"
              << " "
              << "Account Holder Name"
              << " "
              << "Address"
              << " "
              << "Contact"
              << " "
              << "Total balance " << std::endl;

    for (auto &account : bankData.accountHolderData)
    {
        if (accountNumber == account.accountNumber)
        {
            std::cout << account.accountNumber << " " << account.holderName << " " << account.holderAddress << " " << account.holderContact << " " << account.totalBalance << std::endl;
            break;
        }
    }
}

int Admin::closeAccount(Bank &bankData)
{
    InputValidator input;
    int accountNumber;
    std::cout << "Enter Account Number to close: ";
    while (true)
    {
        std::cin >> accountNumber;
        if (input.isValidInput(accountNumber))
            break;
        else
            std::cout << "you have entered invalid account number.Enter valid account number" << std::endl;
    }

    bool found = false;
    int index = 0;
    for (auto &account : bankData.accountHolderData)
    {
        index++;
        if (account.accountNumber == accountNumber)
        {
            found = true;
            bankData.accountHolderData.erase(bankData.accountHolderData.begin() + index - 1);
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

void Admin::logout()
{
    InputValidator input;
    std::cout << "Want to logout.\nPress y for YES.\nPress n for NO" << std::endl;
    char logoutChoice;
    while (true)
    {
        std::cin >> logoutChoice;
        if (input.isValidInput(logoutChoice))
            break;
        else
            continue;
    }

    if (logoutChoice == 'y')
    {
        std::cout << "Logged out successfully" << std::endl;
        isLoggedIn = false;
    }
}