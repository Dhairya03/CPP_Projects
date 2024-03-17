#include "AccountHolderChoice.h"
#include "inputValidator.h"
#include <iostream>

bool AccountHolderChoice::isValidChoice(){
    return(choice>=1 && choice<=6);
}
int AccountHolderChoice::getChoicesList()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Withraw money from Account" << std::endl;
    std::cout << "2.Deposit money in Account" << std::endl;
    std::cout << "3.Get Mini Bank Statement" << std::endl;
    std::cout << "4.Get Bank Statement" << std::endl;
    std::cout << "5.Show Balance" << std::endl;
    std::cout << "6.EXIT" << std::endl;
}

int AccountHolderChoice::setChoice()
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

int AccountHolderChoice::handleChoice(){
    switch (choice)
    {
    case 1:
        user->withdrawMoney();
        break;

    case 2:
        user->depositMoney();
        break;

    case 3:
        user->getMiniBankStatement();
        break;

    case 4:
        user->getBankStatement();
        break;

    case 5:
        user->showBalance();
        break;

    case 6:
        user->logout();
        break;

    default:
        std::cout
            << "You have selected invalid operation to perform."
            << std::endl;
        break;
    }
}