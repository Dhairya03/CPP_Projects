#include "UserChoice.h"
#include "constants.h"
#include "inputValidator.h"
#include <iostream>

int UserChoice::getChoicesList()
{
    std::cout << "Want to enter as:\n"
              << admin << ". Admin \n"
              << accountHolder << ". AccountHolder \n"
              << "3"
              << ".EXIT" << std::endl;
}

bool UserChoice::isValidChoice()
{
    if (choice >= 1 && choice <= 3)
    {
        return true;
    }
    else
    {
        std::cout << "Please enter a valid choice.Enter 1, 2 or 3 only " << std::endl;
        return false;
    }
}

int UserChoice::setChoice()
{
    InputValidator inputValidator;
    while (true)
    {
        std::cin >> choice;
        if (inputValidator.isValidInput(choice) && isValidChoice())
        {
            break;
        }
    }
}

int UserChoice::handleChoice()
{
    while (true)
    {
        if (choice == admin)
        {
            Admin admin(accounts);
            admin.adminLogin();
            while (admin.isLoggedIn)
            {
                bankUser = &admin;
                showAdminChoices();
                std::cin >> operatorChoice;
                if (inputValidator.isValidInput(operatorChoice))
                {
                    inputValidator.setOperatorChoice(operatorChoice);
                }
                // admin.performOperation(inputValidator.getOperatorChoice());
                handleAdminOperation(bankUser, operatorChoice);
            }
        }
        else if (choice == accountHolder)
        {
            AccountHolder user(accounts);
            user.login();
            while (user.isLoggedIn)
            {
                bankUser = &user;
                showAccountHolderChoices();
                std::cin >> operatorChoice;
                if (inputValidator.isValidInput(operatorChoice))
                {
                    inputValidator.setOperatorChoice(operatorChoice);
                }
                handleAccountHolderOperation(bankUser, operatorChoice);
            }
        }
        else
        {
            break;
        }
    }
}