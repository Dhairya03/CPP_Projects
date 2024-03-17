#include "accountHolder.h"
#include "inputValidator.h"

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
