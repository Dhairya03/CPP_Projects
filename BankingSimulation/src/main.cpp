#include <iostream>
#include <vector>
#include "bank.h"
#include "admin.h"
#include "accountHolder.h"
#include "inputValidator.h"
#include "constants.cpp"

int main()
{
    std::cout << "Banking Simulation" << std::endl;
    Bank bankData;//account and transaction data
    InputValidator input;

    do
    {
        std::cout << "Want to Login as:\nAdmin "<<admin<< "\nAccountHolder "<<accountHolder << std::endl;

        input.getUserChoice();

        if (input.isValidUserChoice())
        {
            // std::cout<<"Valid choice"<<std::endl;
            if (input.userChoice == accountHolder)
            {
                AccountHolder user;
                do
                {
                    user.showOperationChoices();
                    user.performOperation(input.getOperatorChoice());
                    std::cout << "Want to exit.\nPress q to quit.\nPress c to continue" << std::endl;
                    std::cin >> input.continueChoice;
                } while (input.continueChoice == 'c');
            }
            else
            {
                Admin admin;
                do
                {
                    admin.adminLogin();
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
