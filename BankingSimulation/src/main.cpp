#include <iostream>
#include <vector>
class Transaction;
class Admin;
class AccountHolder;
// Admin adminData{0};

class Bank
{
protected:
    std::vector<AccountHolder> accountHolderData;
    std::vector<Transaction> transactionDetails;
    Admin adminData;
public:
};

class Transaction
{
public:
    int accountNumber{};
    int transactionId;
    double transactionAmount;
    double netBalance;
    std::string transactionType;

    Transaction(int accNum, int transId, double transAmount, double netBal, std::string transType)
    {
        accountNumber = accNum;
        transactionId = transId;
        transactionAmount = transAmount;
        netBalance = netBal;
        transactionType = transType;
    }
};

class AccountHolder : public Bank
{
public:
    int accountNumber{4000};
    std::string holderName;
    long holderContact;
    std::string holderAddress;
    double totalBalance{};

    void showOperationChoices()
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

    void performOperation(int operationChoice)
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

    void seeUserList()
    {
        std::cout << "User List is" << std::endl;
        for (auto &account : accountHolderData)
        {
            std::cout << account.accountNumber << " " << account.holderName << " " << account.totalBalance << std::endl;
        }
    }

    void seeParticularUser()
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

    int createAccount()
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

    int withdrawMoney()
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
    }

    int depositMoney()
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
    }

    int getMiniBankStatement()
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
    }

    int getBankStatement()
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
    }

    int showBalance()
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
    }

    int closeAccount()
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
};

class Admin : public Bank
{
public:
    int adminId{};
    int adminPassword{};

public:
    Admin()
    {

        adminId = 101;
        adminPassword = 123456;
    }

    int adminLogin()
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

    void showOperationChoices()
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

    void performOperation(int operationChoice)
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

    void seeUserList()
    {
        std::cout << "User List is" << std::endl;
        for (auto &account : accountHolderData)
        {
            std::cout << account.accountNumber << " " << account.holderName << " " << account.totalBalance << std::endl;
        }
    }

    void seeParticularUser()
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

    int withdrawMoney()
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
    }

    int depositMoney()
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
    }

    int getMiniBankStatement()
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
    }

    int getBankStatement()
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
    }

    int showBalance()
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
    }

    int closeAccount()
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
};

class InputValidator
{

public:
    int userChoice{};
    int operationChoice{};
    char continueChoice{};
    InputValidator()
    {
    }
    int getUserChoice()
    {
        std::cin >> userChoice;
        return userChoice;
    }
    int getOperatorChoice()
    {
        std::cin >> operationChoice;
        return operationChoice;
    }
    bool isValidUserChoice()
    {

        return (userChoice == 1 || userChoice == 2) ? true : false;
    }
};

int main()
{

    std::cout << "Banking Simulation" << std::endl;
    InputValidator input;
    do
    {
        std::cout << "Want to Login as:\nPress 1 as Account Holder.\nPress 2 as Admin" << std::endl;

        input.getUserChoice();
        if (input.isValidUserChoice())
        {
            // std::cout<<"Valid choice"<<std::endl;
            if (input.userChoice == 1)
            {
                AccountHolder user1;
                do
                {
                    user1.showOperationChoices();
                    user1.performOperation(input.getOperatorChoice());
                    std::cout << "Want to exit.\nPress q to quit.\nPress c to continue" << std::endl;
                    std::cin >> input.continueChoice;
                } while (input.continueChoice == 'c');
            }
            else
            {
                Admin admin;
                do
                {
                    std::cout << "++++++";
                    admin.adminLogin();
                    std::cout << "--------";
                    admin.showOperationChoices();
                    admin.performOperation(input.getOperatorChoice());
                    std::cout << "Want to log out.\nPress q to quit.\nPress c to continue" << std::endl;
                    std::cin >> input.continueChoice;

                } while (input.continueChoice == 'c');
            }
        }
        else
        {
            std::cout << "Invalid Choice" << std::endl;
        }
        std::cout << "Do you want to exit\nPress q to quit \n Press c to continue" << std::endl;
        std::cin >> input.continueChoice;
    } while (input.continueChoice == 'c');
}
