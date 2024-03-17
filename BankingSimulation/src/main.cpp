#include <iostream>
#include <vector>
#include "bank.h"
#include "constants.h"
#include "admin.h"
#include "accountHolder.h"
#include "inputValidator.h"
#include "account.h"
#include "transaction.h"
#include"handleOperation.h"

int main()
{
    int userChoice;
    std::cout << "Banking Simulation" << std::endl;
    Bank bankData; 
    InputValidator inputValidator;
    HandleOperation operation;

    do
    {
        std::cout << "Want to enter as:\n"
                  << admin << ". Admin \n"
                  << accountHolder << ". AccountHolder " << std::endl;

        std::cin>>userChoice;
        inputValidator.setUserChoice();

        if (inputValidator.isValidUserChoice())
        {
            if (inputValidator.getUserChoice() == accountHolder)
            {
                AccountHolder user;
                do
                {
                    operation.showAccountHolderChoices();
                    operation.setOperationChoice();
                    operation.performAccountHolderOperation(user, bankData);

                } while (!user.logout());
            }
            else
            {
                Admin admin;
                admin.login();
                while (admin.isLoggedIn)
                {
                    operation.showAdminChoices();
                    operation.setOperationChoice();
                    operation.performAdminOperation(admin, bankData);
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
