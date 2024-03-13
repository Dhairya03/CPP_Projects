#include"bankServer.h"
#include<gmock/gmock.h>

class MockBankServer:public BankServer{
    public:
    MOCK_METHOD(void,Connect,(),(override));
    MOCK_METHOD(void, Disconnect,(),(override));
    MOCK_METHOD(void, Credit,(int,int),(override));
    MOCK_METHOD(void,Withdraw,(int,int),(override));
    MOCK_METHOD(bool,DoubleTransaction,(int,int,int),(override));
    MOCK_METHOD(int,GetBalance,(int),(override));    
};