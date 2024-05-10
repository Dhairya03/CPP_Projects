#include "Elevator.h"
#include "mockRequest.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class ElevatorTest : public ::testing::Test
{
public:
    IElevator *elevator;
    IRequest *fakeRequest;
    MockRequest *request;
    std::mutex mtx;
    std::condition_variable cv;
    void SetUp()
    {
        elevator = new Elevator(1, Idle, 0);
        request = new MockRequest();
    }
    void TearDown()
    {
        delete elevator;
        delete request;
    }
};

TEST_F(ElevatorTest, WhenRequestDirectionIsUp_ThenStopsAreAdded)
{
    EXPECT_CALL(*request, getDirection()).WillOnce(::testing::Return(Up));
    EXPECT_CALL(*request, getFloor()).WillOnce(::testing::Return(5));
    EXPECT_TRUE(elevator->addStops(request, 0));
}

TEST_F(ElevatorTest, WhenRequestDirectionIsDown_ThenStopsAreAdded)
{
    EXPECT_CALL(*request, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*request, getFloor()).WillOnce(::testing::Return(7));
    EXPECT_TRUE(elevator->addStops(request, 0));
}

// TEST_F(ElevatorTest, WhenRequestDirectionIsNone_ThenStopsAreNotAdded)
// {
//     EXPECT_CALL(*request, getDirection()).WillRepeatedly(::testing::Return(None));
//     EXPECT_FALSE(elevator->addStops(request, 0));
// }
