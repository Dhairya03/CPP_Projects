#include "admin.h"
#include "constants.h"
#include "inputValidator.h"

// Since extern is used it will be declared in constants.h and can be defined anywhere in the files
Admin adminData(101, 123456);

// Admin::Admin()
// {
// }

Admin::Admin(int adminId, int adminPassword)
{
    this->adminId = adminId;
    this->adminPassword = adminPassword;
}

void Admin::adminLogin()
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
}

int Admin::createAccount()
{
    std::string holderName;
    std::cout << "Enter Account Holder Details" << std::endl;

    Account newAccount;
    std::cout << "Name" << std::endl;
    std::cin >> holderName;
    newAccount.setHolderName(holderName);

    std::cout << "+++";
    newAccount.setAccountNumber(initialAccountNumber + bankData->accounts.size() + 1);
    newAccount.setTotalBalance(0);

    bankData->accounts.push_back(newAccount);

    std::cout << "Account created successfully." << std::endl;
    std::cout << "Your account number is " << newAccount.getAccountNumber() << std::endl;
    return 0;
}

void Admin::showUserList()
{
    bool found = false;
    std::cout << "User List is" << std::endl;
    std::cout << "AccountNumber"
              << " "
              << "AccountHolderName"
              << " "
              << "TotalBalance" << std::endl;

    for (auto &account : bankData->accounts)
    {
        found = true;
        std::cout << account.getAccountNumber() << " " << account.getHolderName() << " " << account.getTotalBalance() << std::endl;
    }

    if (!found)
    {
        std::cout << "No User data found" << std::endl;
    }
}

void Admin::showParticularUser()
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

    for (auto &account : bankData->accounts)
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
}

int Admin::closeAccount()
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

    for (auto &account : bankData->accounts)
    {
        index++;
        if (account.getAccountNumber() == accountNumber)
        {
            found = true;
            bankData->accounts.erase(bankData->accounts.begin() + index - 1);
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
}

bool Admin::login()
{
}

int Admin::withdrawMoney()
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
    for (auto &account : bankData->accounts)
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

int Admin::depositMoney()
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
    for (auto &account : bankData->accounts)
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

bool Admin::printStatement(Account &account, int transactionCount)
{
    int totalTransactions=account.transactions.size();
    bool found = false;
    if (!totalTransactions)
    {
        std::cout << "No transactions for this account Number" << std::endl;
        return false;
    }
    else if(!transactionCount){
        transactionCount=totalTransactions;
    }
    for (int index = 0; index < transactionCount; index++)
    {
        Transaction transaction = account.transactions[index];
        std::cout << "Transaction ID: " << transaction.getTransactionId() << std::endl;
        std::cout << "Transaction Amount: " << transaction.getTransactionAmount() << std::endl;
        std::cout << "Transaction Type:" << transaction.getTransactionType() << std::endl;
        std::cout << "Net Balance: " << transaction.getNetBalance() << std::endl;
    }
    
    return true;
}
int Admin::getMiniBankStatement()
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
    for (auto &account : bankData->accounts)
    {
        if (account.getAccountNumber() == accountNumber)
        {
            if (printStatement(account))
                count++;

            if (count >= 5)
                break;
        }
    }
    if (count == 0)
        std::cout << "No transactions found for the account number " << accountNumber << std::endl;

    return 0;
}

int Admin::getBankStatement()
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
    for (auto &transaction : bankData->transactionDetails)
    {
        if (findStatement(transaction, accountNumber))
            found = true;
    }
    if (!found)
        std::cout << "No transaction for the account Number " << accountNumber << std::endl;
    return found;
}

int Admin::showBalance()
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
