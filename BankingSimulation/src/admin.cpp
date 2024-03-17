#include "admin.h"
#include "constants.h"
#include "inputValidator.h"

// Since extern is used it will be declared in constants.h and can be defined anywhere in the files
Admin adminData(101, 123456);

Admin::Admin()
{
}

Admin::Admin(int adminId, int adminPassword)
{
    this->adminId = adminId;
    this->adminPassword = adminPassword;
}

bool Admin::login()
{
    InputValidator inputValidator;
    std::cout << "Enter your Login Id" << std::endl;
    while (true)
    {
        std::cin >> adminId;
        if (inputValidator.isValidInput(adminId))
            break;
        else
            std::cout << "Invalid Id. Please enter again" << std::endl;
    }

    std::cout << "Enter you password" << std::endl;
    while (true)
    {
        std::cin >> adminPassword;
        if (inputValidator.isValidInput(adminPassword))
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
    return isLoggedIn;
}

void Admin::createAccount(Bank &bankData)
{
    std::string holderName;
    std::string holderAddress;
    long holderContact;
    std::cout << "Enter Account Holder Details" << std::endl;

    Account newAccount;
    std::cout << "Name" << std::endl;
    std::cin >> holderName;
    std::cout << "Address" << std::endl;
    std::cin >> holderAddress;
    std::cout << "Contact" << std::endl;
    std::cin >> holderContact;

    newAccount.setHolderName(holderName);
    newAccount.setHolderAddress(holderAddress);
    newAccount.setHolderContact(holderContact);
    newAccount.setAccountNumber(initialAccountNumber + bankData.accountHolderData.size() + 1);
    newAccount.setTotalBalance(0);

    bankData.accountHolderData.push_back(newAccount);

    std::cout << "Account created successfully." << std::endl;
    std::cout << "Your account number is " << newAccount.getAccountNumber() << std::endl;
}

bool Admin::showUserList(Bank &bankData)
{
    bool found = false;
    std::cout << "User List is" << std::endl;
    std::cout << "AccountNumber"
              << " "
              << "AccountHolderName"
              << " "
              << "TotalBalance" << std::endl;

    for (auto &account : bankData.accountHolderData)
    {
        found = true;
        std::cout << account.getAccountNumber() << " " << account.getHolderName() << " " << account.getTotalBalance() << std::endl;
    }

    if (!found)
    {
        std::cout << "No User data found" << std::endl;
    }
    return found;
}

bool Admin::showParticularUser(Bank &bankData)
{
    InputValidator inputValidator;
    int accountNumber;
    bool found = false;
    std::cout << "Enter account Number of which you want to see details" << std::endl;

    while (true)
    {
        std::cin >> accountNumber;
        if (inputValidator.isValidInput(accountNumber))
            break;
        else
            std::cout << "you have entered invalid account number.Enter valid account number" << std::endl;
    }

    std::cout << "Requested User is" << std::endl;
    std::cout << "AccountNumber"
              << " "
              << "AccountHolderName"
              << " "
              << "Address"
              << " "
              << "Contact"
              << " "
              << "TotalBalance " << std::endl;

    for (auto &account : bankData.accountHolderData)
    {
        if (accountNumber == account.getAccountNumber())
        {
            found = true;
            std::cout << account.getAccountNumber() << " " << account.getHolderName() << " " << account.getHolderAddress() << " " << account.getHolderContact() << " " << account.getTotalBalance() << std::endl;
            break;
        }
    }

    if (!found)
    {
        std::cout << "No User data found" << std::endl;
    }
    return found;
}

int Admin::closeAccount(Bank &bankData)
{
    InputValidator inputValidator;
    int accountNumber;
    std::cout << "Enter Account Number to close: ";

    while (true)
    {
        std::cin >> accountNumber;
        if (inputValidator.isValidInput(accountNumber))
            break;
        else
            std::cout << "you have entered invalid account number.Enter valid account number" << std::endl;
    }

    bool found = false;
    int index = 0;

    for (auto &account : bankData.accountHolderData)
    {
        index++;
        if (account.getAccountNumber() == accountNumber)
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
    return found;
}

bool Admin::logout()
{
    InputValidator inputValidator;
    std::cout << "Want to logout.\nPress y for YES.\nPress n for NO" << std::endl;
    char logoutChoice;

    while (true)
    {
        std::cin >> logoutChoice;
        if (inputValidator.isValidInput(logoutChoice))
            break;
        else
            continue;
    }

    if (logoutChoice == 'y')
    {
        std::cout << "Logged out successfully" << std::endl;
        isLoggedIn = false;
    }
    else {
        isLoggedIn=true;
    }
    return !isLoggedIn;
}