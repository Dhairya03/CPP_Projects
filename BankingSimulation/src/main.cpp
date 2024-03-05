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
    InputValidator inputValidator;

    do
    {
        std::cout << "Want to enter as:\n"
                  << admin << ". Admin \n"
                  << accountHolder << ". AccountHolder " << std::endl;

        inputValidator.setUserChoice();

        if (inputValidator.isValidUserChoice())
        {
            if (inputValidator.getUserChoice() == accountHolder)
            {
                AccountHolder user;
                do
                {
                    user.showOperationChoices();
                    inputValidator.setOperatorChoice();
                    user.performOperation(inputValidator.getOperatorChoice(), bankData);

                } while (!user.logout());
            }
            else
            {
                Admin admin;
                admin.adminLogin();
                while (admin.isLoggedIn)
                {
                    admin.showOperationChoices();
                    inputValidator.setOperatorChoice();
                    admin.performOperation(inputValidator.getOperatorChoice(), bankData);
                }
            }
        }
        else
        {
            std::cout << "Invalid Choice" << std::endl;
        }

        std::cout << "Do you want to close the application.\nPress y for Yes \nPress n for NO" << std::endl;
        inputValidator.setContinueChoice();

    } while (inputValidator.getContinueChoice() == 'n');
}
