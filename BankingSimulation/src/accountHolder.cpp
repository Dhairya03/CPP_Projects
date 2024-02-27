#include "accountHolder.h"

void AccountHolder::showOperationChoices()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Request to create Account" << std::endl;
    std::cout << "2.Withraw money from Account" << std::endl;
    std::cout << "3.Deposit money in Account" << std::endl;
    std::cout << "4.Get Mini Bank Statement" << std::endl;
    std::cout << "5.Get Bank Statement" << std::endl;
    std::cout << "6.Show Balance" << std::endl;
    std::cout << "7.Request to close Account" << std::endl;
    std::cout << "8.EXIT" << std::endl;
}

void AccountHolder::performOperation(int operationChoice)
{
    switch (operationChoice)
    {
    case 1:
        createAccount();
        break;

    case 2:
        withdrawMoney();
        break;
    case 3:
        depositMoney();
        break;
    case 4:
        getMiniBankStatement();
        break;
    case 5:
        getBankStatement();
        break;
    case 6:
        showBalance();
        break;
    case 7:
        closeAccount();
        break;
    case 8:
    {
        seeUserList();
        seeParticularUser();
        break;
    }
    default:
        std::cout << "You have selected invalid Operation to perform." << std::endl;
        break;
    }
}

void AccountHolder::seeUserList()
{
    std::cout << "User List is" << std::endl;
    for (auto &account : accountHolderData)
    {
        std::cout << account.accountNumber << " " << account.holderName << " " << account.totalBalance << std::endl;
    }
}

void AccountHolder::seeParticularUser()
{
    int accountNumber;
    std::cout << "Enter account Number of which you want to see details" << std::endl;
    std::cin >> accountNumber;
    std::cout << "Requested User is" << std::endl;
    for (auto &account : accountHolderData)
    {
        if (accountNumber == account.accountNumber)
        {
            std::cout << account.accountNumber << " " << account.holderName << " " << account.holderAddress << " " << account.holderContact << " " << account.totalBalance << std::endl;
        }
    }
}

int AccountHolder::createAccount()
{
    std::cout << "Enter your Details" << std::endl;

    std::cout << "Name" << std::endl;
    std::cin >> holderName;
    std::cout << "Address" << std::endl;
    std::cin >> holderAddress;
    std::cout << "Contact" << std::endl;
    std::cin >> holderContact;

    AccountHolder newAccount;
    newAccount.accountNumber = accountNumber + 1;
    newAccount.holderName = holderName;
    newAccount.holderContact = holderContact;
    newAccount.holderAddress = holderAddress;
    newAccount.totalBalance = 0;

    accountHolderData.push_back(newAccount);

    std::cout << "Account created successfully." << std::endl;
    std::cout << "Your account number is " << newAccount.accountNumber << std::endl;
}

int AccountHolder::closeAccount()
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
            // accountHolderData.erase(account);
            std::cout << "Account Closed Successfully" << std::endl;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
}
