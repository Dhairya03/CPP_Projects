#include "bank.h"
#include "inputValidator.h"

bool Bank::adminLogin(int id, int pwd)
{
    return true;
}

int Bank::withdrawMoney(Bank &bankData)
{
    InputValidator input;
    int withdrawAccountNumber;
    double withdrawAmount;

    std::cout << "Enter Account Number from which you want to withdraw: ";
    while (true)
    {
        std::cin >> withdrawAccountNumber;
        if (input.isValidInput(withdrawAccountNumber))
            break;
        else
            std::cout << "Enter valid account Number" << std::endl;
    }

    bool found = false;
    for (auto &account : accountHolderData)
    {
        if (account.accountNumber == withdrawAccountNumber)
        {
            found = true;
            std::cout << "Enter Amount to Withdraw: ";
            while (true)
            {
                std::cin >> withdrawAmount;
                if (input.isValidInput(withdrawAmount))
                    break;
                else
                    std::cout << "You have entered invalid ammount.\nEnter valid amount" << std::endl;
            }

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

int Bank::depositMoney(Bank &bankData)
{
    InputValidator input;
    int depositAccountNumber;
    double depositAmount;

    std::cout << "Enter Account Number in which you want to deposit ";
    while (true)
    {
        std::cin >> depositAccountNumber;
        if (input.isValidInput(depositAccountNumber))
            break;
        else
            std::cout << "Enter valid account number" << std::endl;
    }

    bool found = false;
    for (auto &account : accountHolderData)
    {
        if (account.accountNumber == depositAccountNumber)
        {
            found = true;
            std::cout << "Enter Amount to Deposit: ";
            while (true)
            {
                std::cin >> depositAmount;
                if (input.isValidInput(depositAmount))
                    break;
                else
                    std::cout << "You have entered invalid ammount.\nEnter valid amount" << std::endl;
            }

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

int Bank::getMiniBankStatement(Bank &bankData)
{
    InputValidator input;
    int accountNumber;
    std::cout << "Enter Account Number to get Mini Bank Statement: ";
    while (true)
    {
        std::cin >> accountNumber;
        if (input.isValidInput(accountNumber))
            break;
        else
            std::cout << "you have entered invalid account number. Enter valid account number" << std::endl;
    }

    std::cout << "Mini Bank Statement for Account Number " << accountNumber << ":" << std::endl;
    int count = 0;
    for (auto &transaction : transactionDetails)
    {
        if (transaction.accountNumber == accountNumber)
        {
            std::cout << "Transaction ID: " << transaction.transactionId << std::endl;
            std::cout << "Transaction Amount: " << transaction.transactionAmount << std::endl;
            std::cout << "Transaction Type:" << transaction.transactionType << std::endl;
            std::cout << "Net Balance: " << transaction.netBalance << std::endl;
            count++;
        }
        if (count >= 5)
            break;
    }
    if (count == 0)
        std::cout << "No transactions found for the account number " << accountNumber << std::endl;
    return 0;
}

int Bank::getBankStatement(Bank &bankData)
{
    InputValidator input;
    int accountNumber;
    std::cout << "Enter Account Number to get Bank Statement: ";
    while (true)
    {
        std::cin >> accountNumber;
        if (input.isValidInput(accountNumber))
            break;
        else
            std::cout << "You have entered invalid account number.\nEnter valid account number" << std::endl;
    }

    std::cout << "Bank Statement for Account Number " << accountNumber << ":" << std::endl;
    bool found = false;
    for (auto &transaction : transactionDetails)
    {
        if (transaction.accountNumber == accountNumber)
        {
            found = true;
            std::cout << "Transaction ID: " << transaction.transactionId << std::endl;
            std::cout << "Transaction Amount: " << transaction.transactionAmount << std::endl;
            std::cout << "Transaction Type:" << transaction.transactionType << std::endl;
            std::cout << "Net Balance: " << transaction.netBalance << std::endl;
        }
    }
    if (!found)
        std::cout << "No transaction for the account Number " << accountNumber << std::endl;
    return 0;
}

int Bank::showBalance(Bank &bankData)
{
    InputValidator input;
    int accountNumber;
    std::cout << "Enter Account Number to get Total balance: ";
    while (true)
    {
        std::cin >> accountNumber;
        if (input.isValidInput(accountNumber))
            break;
        else
            std::cout << "You have entered invalid account number.\nEnter valid account number" << std::endl;
    }

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