#include<gtest/gtest.h>
#include<gmock/gmock.h>
#include "MockAdmin.h"
#include "handleOperation.h"

class handleOperationTest:public ::testing::Test{
public:
MockAdmin mockAdmin;

};

// TEST_F(handleOperationTest,getValidOperationChoiceTrue){

// }