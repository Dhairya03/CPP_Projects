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
        std::cout << "Want to enter as:\nAdmin " << admin << "\nAccountHolder " << accountHolder << std::endl;

        input.getUserChoice();

        if (input.isValidUserChoice())
        {
            if (input.userChoice == accountHolder)
            {
                AccountHolder user;
                do
                {
                    user.showOperationChoices();
                    user.performOperation(input.getOperatorChoice());

                } while (user.logout());
            }
            else
            {
                Admin admin;
                do
                {
                    if (admin.adminLogin())
                    {
                        std::cout<<"Successful Login"<<std::endl;
                        admin.showOperationChoices();
                        admin.performOperation(input.getOperatorChoice());
                    }
                    else
                    {
                        std::cout << "Invalid Credentials" << std::endl;
                    }

                } while (admin.logout());
            }
        }
        else
        {
            std::cout << "Invalid Choice" << std::endl;
        }
        std::cout << "Do you want to close the application.\nPress q to quit \n Press c to continue" << std::endl;
        std::cin >> input.continueChoice;
    } while (input.continueChoice == 'c');
}
