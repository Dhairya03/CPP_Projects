#ifndef ACCOUNT_HOLDER_CHOICE_H
#define ACCOUNT_HOLDER_CHOICE_H

#include "inputChoice.h"

class AccountHolderChoice : public InputChoice
{
    bool isValidChoice();

public:
    int getChoicesList();
    int setChoice();
    int handleChoice();
};
#endif