#include "AdminChoice.h"
#include "inputValidator.h"
#include <iostream>

bool AdminChoice::isValidChoice(){
    return(choice>=1 && choice<=10);
}
int AdminChoice::getChoicesList()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Create Account" << std::endl;
    std::cout << "2.See the list of Account Holders" << std::endl;
    std::cout << "3.See the account details of a particular Account Holder" << std::endl;
    std::cout << "4.Withraw money from Account" << std::endl;
    std::cout << "5.Deposit money in Account" << std::endl;
    std::cout << "6.Get Mini Bank Statement" << std::endl;
    std::cout << "7.Get Bank Statement" << std::endl;
    std::cout << "8.Show Balance" << std::endl;
    std::cout << "9.Close Account" << std::endl;
    std::cout << "10.Logout" << std::endl;
}

int AdminChoice::setChoice()
{
    InputValidator inputValidator;
    while (true)
    {
        std::cin >> choice;
        if(inputValidator.isValidInput(choice)&&isValidChoice()){
            break;
        }
    }
}

int AdminChoice::handleChoice(){
    Admin *admin = (Admin *)&user;
    switch (operationChoice)
    {
    case 1:
        admin->createAccount();
        break;

    case 2:
        admin->showUserList();
        break;

    case 3:
        admin->showParticularUser();
        break;

    case 4:
        user->withdrawMoney();
        break;

    case 5:
        user->depositMoney();
        break;

    case 6:
        user->getMiniBankStatement();
        break;

    case 7:
        user->getBankStatement();
        break;

    case 8:
        user->showBalance();
        break;

    case 9:
        admin->closeAccount();
        break;

    case 10:
        user->logout();
        break;

    default:
        std::cout << "You have selected invalid Operation to perform." << std::endl;
        break;
    }
}

