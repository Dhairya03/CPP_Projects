#include"bankServer.h"

class AtmMachine{
    BankServer* bankServer;

    public:
    AtmMachine(BankServer* _bankServer):bankServer(_bankServer){}
    bool Withdraw(int accountNumber, int value){
        bool result=false;
        bankServer->Connect();
        auto available_balance=bankServer->GetBalance(accountNumber);
        if(available_balance>=value){
            bankServer->Withdraw(accountNumber,value);
            result=true;
        }
        bankServer->Disconnect();
        return result;
    }
};