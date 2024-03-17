#ifndef INPUT_CHOICE_H
#define INPUT_CHOICE_H

class InputChoice
{
protected:
    int choice;

public:
    virtual int getChoicesList() = 0;
    virtual int setChoice() = 0;
    virtual int handleChoice() = 0;
};

#endif