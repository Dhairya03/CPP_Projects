#ifndef BANK_SERVER_H
#define BANK_SERVER_H

class BankServer{
    public:
    virtual ~BankServer(){}
    virtual void Connect()=0;
    virtual void Disconnect()=0;
    virtual void Credit(int accNum, int value)=0;
    virtual void Withdraw(int accNum, int value)=0;
    virtual bool DoubleTransaction(int accNum, int value1, int value2)=0;
    virtual int GetBalance(int accNum)=0;
};

#endif