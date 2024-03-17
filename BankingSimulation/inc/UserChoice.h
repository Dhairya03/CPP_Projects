#ifndef USER_CHOICE_H
#define USER_CHOICE_H

#include "inputChoice.h"

class UserChoice : public InputChoice
{
    bool isValidChoice();
public:
    int getChoicesList();
    int setChoice();
    int handleChoice();
};
#endif