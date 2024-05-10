#include "Request.h"
#include <gtest/gtest.h>

class RequestTest : public ::testing::Test
{
public:
    Request request;
};

TEST_F(RequestTest, WhenRandomFloorIsGenerated_ThenFloorIsInRange)
{
    int randomFloor = request.generateRandomFloor(-2,7);
    EXPECT_LE(randomFloor,7);
    EXPECT_GE( randomFloor,-2);
}




