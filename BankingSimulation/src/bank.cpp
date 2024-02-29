#include "bank.h"

bool Bank::adminLogin(int id, int pwd){
    return true;
}

int Bank::withdrawMoney()
{
    int withdrawAccountNumber;
    double withdrawAmount;

    std::cout << "Enter Account Number from which you want to withdraw: ";
    std::cin >> withdrawAccountNumber;

    bool found = false;
    for (auto &account : accountHolderData)
    {
        if (account.accountNumber == withdrawAccountNumber)
        {
            found = true;
            std::cout << "Enter Amount to Withdraw: ";
            std::cin >> withdrawAmount;
            if (withdrawAmount <= account.totalBalance)
            {
                account.totalBalance -= withdrawAmount;
                transactionDetails.push_back(Transaction(account.accountNumber, transactionDetails.size() + 1, withdrawAmount, account.totalBalance, "Withdraw"));

                std::cout << "Withdrawal successful. Updated Balance: " << account.totalBalance << std::endl;
            }
            else
            {
                std::cout << "Insufficient Balance." << std::endl;
            }
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return 0;
}

int Bank::depositMoney()
{
    int depositAccountNumber;
    double depositAmount;

    std::cout << "Enter Account Number in which you want to deposit ";
    std::cin >> depositAccountNumber;

    bool found = false;
    for (auto &account : accountHolderData)
    {
        if (account.accountNumber == depositAccountNumber)
        {
            found = true;
            std::cout << "Enter Amount to Deposit: ";
            std::cin >> depositAmount;
            account.totalBalance += depositAmount;
            transactionDetails.push_back(Transaction(account.accountNumber, transactionDetails.size() + 1, depositAmount, account.totalBalance, "Deposit"));

            std::cout << "Deposit successful. Updated Balance: " << account.totalBalance << std::endl;

            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return 0;
}

int Bank::getMiniBankStatement()
{
    int accountNumber;
    std::cout << "Enter Account Number to get Mini Bank Statement: ";
    std::cin >> accountNumber;

    std::cout << "Mini Bank Statement for Account Number " << accountNumber << ":" << std::endl;
    for (auto &transaction : transactionDetails)
    {
        int count = 1;
        if (transaction.accountNumber == accountNumber)
        {
            std::cout << "Transaction ID: " << transaction.transactionId << std::endl;
            std::cout << "Transaction Amount: " << transaction.transactionAmount << std::endl;
            std::cout << "Transaction Type:" << transaction.transactionType << std::endl;
            std::cout << "Net Balance: " << transaction.netBalance << std::endl;
            count++;
        }
        if (count > 5)
            break;
    }
    return 0;
}

int Bank::getBankStatement()
{
    int accountNumber;
    std::cout << "Enter Account Number to get Bank Statement: ";
    std::cin >> accountNumber;

    std::cout << "Bank Statement for Account Number " << accountNumber << ":" << std::endl;
    for (auto &transaction : transactionDetails)
    {
        if (transaction.accountNumber == accountNumber)
        {
            std::cout << "Transaction ID: " << transaction.transactionId << std::endl;
            std::cout << "Transaction Amount: " << transaction.transactionAmount << std::endl;
            std::cout << "Transaction Type:" << transaction.transactionType << std::endl;
            std::cout << "Net Balance: " << transaction.netBalance << std::endl;
        }
    }
    return 0;
}

int Bank::showBalance()
{
    int accountNumber;
    std::cout << "Enter Account Number to get total balance: ";
    std::cin >> accountNumber;

    bool found = false;
    for (auto &account : accountHolderData)
    {
        if (account.accountNumber == accountNumber)
        {
            found = true;
            std::cout << "Total Balance: " << account.totalBalance << std::endl;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return 0;
}