#include <iostream>
#include <vector>
#include "bank.h"
#include "constants.h"
#include "admin.h"
#include "accountHolder.h"
#include "inputValidator.h"
#include "account.h"
#include "transaction.h"

int main()
{
    std::cout << "Banking Simulation" << std::endl;
    Bank bankData; // account and transaction data
    InputValidator input;

    do
    {
        std::cout << "Want to enter as:\n"
                  << admin << ". Admin \n"
                  << accountHolder << ". AccountHolder " << std::endl;

        input.getUserChoice();
        if (input.isValidUserChoice())
        {
            if (input.userChoice == accountHolder)
            {
                AccountHolder user;
                do
                {
                    user.showOperationChoices();
                    user.performOperation(input.getOperatorChoice(), bankData);

                } while (!user.logout());
            }
            else
            {
                Admin admin;
                admin.adminLogin();
                while (admin.isLoggedIn)
                {
                    admin.showOperationChoices();
                    admin.performOperation(input.getOperatorChoice(), bankData);
                }
            }
        }
        else
        {
            std::cout << "Invalid Choice" << std::endl;
        }

        std::cout << "Do you want to close the application.\nPress y for Yes \nPress n for NO" << std::endl;
        while (true)
        {
            std::cin >> input.continueChoice;
            if (input.isValidInput(input.continueChoice))
                break;
            else
                std::cout << "Enter valid choice.Please try again." << std::endl;
        }
    } while (input.continueChoice == 'n');
}
