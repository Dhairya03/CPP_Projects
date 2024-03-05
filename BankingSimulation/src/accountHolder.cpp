#include "accountHolder.h"
#include "inputValidator.h"

void AccountHolder::showOperationChoices()
{
    std::cout << "Select the operation you want to perform" << std::endl;
    std::cout << "1.Withraw money from Account" << std::endl;
    std::cout << "2.Deposit money in Account" << std::endl;
    std::cout << "3.Get Mini Bank Statement" << std::endl;
    std::cout << "4.Get Bank Statement" << std::endl;
    std::cout << "5.Show Balance" << std::endl;
    std::cout << "6.EXIT" << std::endl;
}

void AccountHolder::performOperation(int operationChoice, Bank &bankData)
{
    switch (operationChoice)
    {
    case 1:
        withdrawMoney(bankData);
        break;

    case 2:
        depositMoney(bankData);
        break;

    case 3:
        getMiniBankStatement(bankData);
        break;

    case 4:
        getBankStatement(bankData);
        break;

    case 5:
        showBalance(bankData);
        break;

    case 6:
        logout();
        break;

    default:
        std::cout << "You have selected invalid operation to perform." << std::endl;
        break;
    }
}

bool AccountHolder::logout()
{
    InputValidator inputValidator;
    std::cout << "Want to exit.\nPress y for Yes.\nPress n for No" << std::endl;
    char exitChoice;

    while (true)
    {
        std::cin >> exitChoice;
        if (inputValidator.isValidInput(exitChoice))
            break;
        else
            continue;
    }

    return (exitChoice == 'y') ? true : false;
}
