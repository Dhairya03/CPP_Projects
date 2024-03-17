#include "accountHolder.h"
#include "inputValidator.h"

void AccountHolder::showOperationChoices()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Withraw money from Account" << std::endl;
    std::cout << "2.Deposit money in Account" << std::endl;
    std::cout << "3.Get Mini Bank Statement" << std::endl;
    std::cout << "4.Get Bank Statement" << std::endl;
    std::cout << "5.Show Balance" << std::endl;
    std::cout << "6.EXIT" << std::endl;
}

void AccountHolder::performOperation(int operationChoice)
{
    switch (operationChoice)
    {
    case 1:
        withdrawMoney();
        break;

    case 2:
        depositMoney();
        break;

    case 3:
        getMiniBankStatement( );
        break;

    case 4:
        getBankStatement( );
        break;

    case 5:
        showBalance( );
        break;

    case 6:
        logout();
        break;

    default:
        std::cout << "You have selected invalid operation to perform." << std::endl;
        break;
    }
}

bool AccountHolder::logout()
{
    InputValidator inputValidator;
    std::cout << "Want to exit.\nPress y for Yes.\nPress n for No" << std::endl;
    char exitChoice;

    while (true)
    {
        std::cin >> exitChoice;
        if (inputValidator.isValidInput(exitChoice))
            break;
        else
            continue;
    }

    return (exitChoice == 'y') ? true : false;
}

int AccountHolder::withdrawMoney()
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
    for (auto &account : bankData->accountHolderData)
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
                newTransaction.setTransactionId(account.transactions.size() + 1);
                newTransaction.setTransactionAmount(withdrawAmount);
                newTransaction.setNetBalance(account.getTotalBalance());
                newTransaction.setTransactionType("Withdraw");

                account.transactions.push_back(newTransaction);

                std::cout << "Withdrawal successful. Updated Balance: " << account.getTotalBalance() << std::endl;
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

int AccountHolder::depositMoney( )
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
    for (auto &account : bankData->accountHolderData)
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
            newTransaction.setTransactionId(account.transactions.size() + 1);
            newTransaction.setTransactionAmount(depositAmount);
            newTransaction.setNetBalance(account.getTotalBalance());
            newTransaction.setTransactionType("Deposit");

            account.transactions.push_back(newTransaction);

            std::cout << "Deposit successful. Updated Balance: " << account.getTotalBalance() << std::endl;

            break;
        }
    }
    if (!found)
    {
        std::cout << "Account not found." << std::endl;
    }
    return 0;
}

bool AccountHolder::findStatement( Transaction &transaction, int accountNumber)
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
int AccountHolder::getMiniBankStatement( )
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
    for (auto &transaction : bankData->accountHolderData)
    {
        // if (findStatement( transaction, accountNumber))
        //     count++;

        if (count >= 5)
            break;
    }
    if (count == 0)
        std::cout << "No transactions found for the account number " << accountNumber << std::endl;

    return 0;
}

int AccountHolder::getBankStatement( )
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
    for (auto &transaction : bankData->accountHolderData)
    {
        // if (findStatement(transaction, accountNumber))
        //     found = true;
    }
    if (!found)
        std::cout << "No transaction for the account Number " << accountNumber << std::endl;
    return found;
}

int AccountHolder::showBalance( )
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
    for (auto &account : bankData->accountHolderData)
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
    return 0;
}

