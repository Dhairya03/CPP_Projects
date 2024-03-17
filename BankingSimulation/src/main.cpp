#include <iostream>
#include <vector>
#include "Accounts.h"
#include "constants.h"
#include "admin.h"
#include "accountHolder.h"
#include "inputValidator.h"
#include "account.h"
#include "transaction.h"

void showAccountHolderChoices()
{
    
}

void showAdminChoices()
{
    
}

bool handleAccountHolderOperation(BankUser *user, int operationChoice)
{
    
}

bool handleAdminOperation(BankUser *user, int operationChoice)
{
    
}
int main()
{
    int userChoice;
    int operatorChoice;
    // char continueChoice;
    BankUser *bankUser;
    std::cout << "Banking Simulation" << std::endl;
    Accounts *accounts; // account and transaction data
    InputValidator inputValidator;

    do
    {
        

        std::cin >> userChoice;
        if (inputValidator.isValidInput(userChoice))
        {
            inputValidator.setUserChoice(userChoice);
            if (inputValidator.isValidUserChoice())
            {
                if (inputValidator.getUserChoice() == accountHolder)
                {
                    
                }
                else
                {
                    
                }
            }
            else
            {
                std::cout << "Invalid Choice" << std::endl;
            }
            std::cout << "Please enter a valid number" << std::endl;
        }

        // std::cout << "Do you want to close the application.\nPress y for Yes \nPress n for NO" << std::endl;
        // std::cin >> continueChoice;
        // if (inputValidator.isValidInput(continueChoice))
        // {
        //     inputValidator.setContinueChoice(continueChoice);
        // }

    } while (userChoice!=3);
}
