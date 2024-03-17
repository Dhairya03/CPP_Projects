#include "bankUser.h"
#include "bank.h"
#include "inputValidator.h"

int BankUser::withdrawMoney(Bank &bankData)
{
    InputValidator inputValidator;
    int withdrawAccountNumber;
    double withdrawAmount;

    std::cout << "Enter Account Number from which you want to withdraw: ";
    while (true)
    {
        std::cin >> withdrawAccountNumber;
        if (inputValidator.isValidInput(withdrawAccountNumber))
            break;
        else
            std::cout << "Enter valid account Number" << std::endl;
    }

    bool found = false;
    for (auto &account : bankData.accountHolderData)
    {
        if (account.getAccountNumber() == withdrawAccountNumber)
        {
            found = true;
            std::cout << "Enter Amount to Withdraw: ";
            while (true)
            {
                std::cin >> withdrawAmount;
                if (inputValidator.isValidInput(withdrawAmount))
                    break;
                else
                    std::cout << "You have entered invalid ammount.\nEnter valid amount" << std::endl;
            }

            if (withdrawAmount <= account.getTotalBalance())
            {
                account.setTotalBalance((-1) * withdrawAmount);

                Transaction newTransaction;
                newTransaction.setAccountNumber(account.getAccountNumber());
                newTransaction.setTransactionId(bankData.transactionDetails.size() + 1);
                newTransaction.setTransactionAmount(withdrawAmount);
                newTransaction.setNetBalance(account.getTotalBalance());
                newTransaction.setTransactionType("Withdraw");

                bankData.transactionDetails.push_back(newTransaction);

                std::cout << "Withdrawal successful. Updated Balance: " << account.getTotalBalance() << std::endl;
            }
            else
            {
                found=false;
                std::cout << "Insufficient Balance." << std::endl;
            }
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return found;
}

int BankUser::depositMoney(Bank &bankData)
{
    InputValidator inputValidator;
    int depositAccountNumber;
    double depositAmount;

    std::cout << "Enter Account Number in which you want to deposit ";
    while (true)
    {
        std::cin >> depositAccountNumber;
        if (inputValidator.isValidInput(depositAccountNumber))
            break;
        else
            std::cout << "Enter valid account number" << std::endl;
    }

    bool found = false;
    for (auto &account : bankData.accountHolderData)
    {
        if (account.getAccountNumber() == depositAccountNumber)
        {
            found = true;
            std::cout << "Enter Amount to Deposit: ";
            while (true)
            {
                std::cin >> depositAmount;
                if (inputValidator.isValidInput(depositAmount))
                    break;
                else
                    std::cout << "You have entered invalid ammount.\nEnter valid amount" << std::endl;
            }

            account.setTotalBalance(depositAmount);

            Transaction newTransaction;
            newTransaction.setAccountNumber(account.getAccountNumber());
            newTransaction.setTransactionId(bankData.transactionDetails.size() + 1);
            newTransaction.setTransactionAmount(depositAmount);
            newTransaction.setNetBalance(account.getTotalBalance());
            newTransaction.setTransactionType("Deposit");

            bankData.transactionDetails.push_back(newTransaction);

            std::cout << "Deposit successful. Updated Balance: " << account.getTotalBalance() << std::endl;

            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return found;
}

bool BankUser::findStatement(Bank &bankData, Transaction &transaction, int accountNumber)
{
    bool found = false;
    if (transaction.getAccountNumber() == accountNumber)
    {
        found = true;
        std::cout << "Transaction ID: " << transaction.getTransactionId() << std::endl;
        std::cout << "Transaction Amount: " << transaction.getTransactionAmount() << std::endl;
        std::cout << "Transaction Type:" << transaction.getTransactionType() << std::endl;
        std::cout << "Net Balance: " << transaction.getNetBalance() << std::endl;
    }
    return found;
}
int BankUser::getMiniBankStatement(Bank &bankData)
{
    InputValidator inputValidator;
    int accountNumber;
    std::cout << "Enter Account Number to get Mini Bank Statement: ";
    while (true)
    {
        std::cin >> accountNumber;
        if (inputValidator.isValidInput(accountNumber))
            break;
        else
            std::cout << "you have entered invalid account number. Enter valid account number" << std::endl;
    }

    std::cout << "Mini Bank Statement for Account Number " << accountNumber << ":" << std::endl;
    int count = 0;
    for (auto &transaction : bankData.transactionDetails)
    {
        if (findStatement(bankData, transaction, accountNumber))
            count++;

        if (count >= 5)
            break;
    }
    if (count == 0)
        std::cout << "No transactions found for the account number " << accountNumber << std::endl;

    return count;
}

int BankUser::getBankStatement(Bank &bankData)
{
    InputValidator inputValidator;
    int accountNumber;
    std::cout << "Enter Account Number to get Bank Statement: ";
    while (true)
    {
        std::cin >> accountNumber;
        if (inputValidator.isValidInput(accountNumber))
            break;
        else
            std::cout << "You have entered invalid account number.\nEnter valid account number" << std::endl;
    }

    std::cout << "Bank Statement for Account Number " << accountNumber << ":" << std::endl;
    bool found = false;
    for (auto &transaction : bankData.transactionDetails)
    {
        if (findStatement(bankData, transaction, accountNumber))
            found = true;
    }
    if (!found)
        std::cout << "No transaction for the account Number " << accountNumber << std::endl;
    return found;
}

int BankUser::showBalance(Bank &bankData)
{
    InputValidator inputValidator;
    int accountNumber;
    std::cout << "Enter Account Number to get Total balance: ";
    while (true)
    {
        std::cin >> accountNumber;
        if (inputValidator.isValidInput(accountNumber))
            break;
        else
            std::cout << "You have entered invalid account number.\nEnter valid account number" << std::endl;
    }

    bool found = false;
    for (auto &account : bankData.accountHolderData)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            found = true;
            std::cout << "Total Balance: " << account.getTotalBalance() << std::endl;
            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return found;
}