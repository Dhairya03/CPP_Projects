#ifndef ADMIN_CHOCICE_H
#define ADMIN_CHOICE_H

#include "inputChoice.h"

class AdminChoice : public InputChoice
{
    bool isValidChoice();
public:
    int getChoicesList();
    int setChoice();
    int handleChoice();
};
#endif