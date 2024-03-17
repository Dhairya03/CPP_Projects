#ifndef MOCK_ADMIN_H
#define MOCK_ADMIN_H

#include <gmock/gmock.h>
#include "IAdmin.h"

class MockAdmin:public IAdmin{
    public:
    MOCK_METHOD(bool,login,(),(override));
    MOCK_METHOD(int , createAccount,(Bank&),(override));
    MOCK_METHOD(int, withdrawMoney,(Bank&),(override));
    MOCK_METHOD(int, depositMoney,(Bank&),(override));
    MOCK_METHOD(bool, findStatement,(Bank& , Transaction &, int accountNumber),(override));
    MOCK_METHOD(int, getMiniBankStatement,(Bank&),(override));
    MOCK_METHOD(int, getBankStatement,(Bank&),(override));
    MOCK_METHOD(int , showBalance,(Bank&),(override));
    MOCK_METHOD(void, showUserList,(Bank&),(override));
    MOCK_METHOD(void, showParticularUser,(Bank&),(override));
    MOCK_METHOD(int, closeAccount,(Bank&),(override));
    MOCK_METHOD(bool,logout,(),(override));
};

#endif