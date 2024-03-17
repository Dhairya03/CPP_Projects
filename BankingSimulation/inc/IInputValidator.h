#ifndef I_INPUTVALIDATOR_H
#define I_INPUTVALIDATOR_H

#include <iostream>

class IInputValidator
{
public:
    virtual int getUserChoice()=0;

    virtual void setUserChoice()=0;

    virtual int getOperatorChoice()=0;

    virtual void setOperatorChoice()=0;

    virtual bool isValidUserChoice()=0;

    virtual char getContinueChoice()=0;

    virtual void setContinueChoice()=0;

    virtual bool isValidInput(int choice)=0;

    virtual bool isValidInput(double choice)=0;

    virtual bool isValidInput(char choice)=0;
};

#endif