#include "Request.h"
#include "mockRequest.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class RequestTest : public ::testing::Test
{
public:
    IRequest *request;
    MockRequest *mockRequest;
    void SetUp()
    {
        request = new Request();
        mockRequest = new MockRequest();
    }
    void TearDown()
    {
        delete request;
        delete mockRequest;
    }
};

TEST_F(RequestTest, WhenRandomFloorIsGenerated_ThenFloorIsInRange)
{
    int randomFloor = request->generateRandomFloor(-2, 7);
    EXPECT_LE(randomFloor, 7);
    EXPECT_GE(randomFloor, -2);
}

TEST_F(RequestTest, WhenDirectionIsSet_ThenGetDirectionReturnsSameDirection)
{
    bool direction = true;
    request->setDirection(direction);
    EXPECT_EQ(request->getDirection(), direction);
}

TEST_F(RequestTest, WhenFloorIsSet_ThenGetFloorReturnSameFloor)
{
    request->setFloor();
    EXPECT_LE(request->getFloor(), 7);
    EXPECT_GE(request->getFloor(), -2);
}
