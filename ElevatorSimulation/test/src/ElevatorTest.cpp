#include "Elevator.h"
#include "mockRequest.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class ElevatorTest : public ::testing::Test
{
public:
    IElevator *elevator;
    MockRequest *mockRequest;

    void SetUp()
    {
        elevator = new Elevator(1, Idle, 0);
        mockRequest = new MockRequest();
    }
    void TearDown()
    {
        delete elevator;
        delete mockRequest;
    }
};

TEST_F(ElevatorTest, WhenRequestDirectionIsUp_ThenStopsAreAdded)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillOnce(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillOnce(::testing::Return(5));
    EXPECT_TRUE(elevator->addStops(mockRequest, 0));
}

TEST_F(ElevatorTest, WhenRequestDirectionIsDown_ThenStopsAreAdded)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillOnce(::testing::Return(7));
    EXPECT_TRUE(elevator->addStops(mockRequest, 0));
}

TEST_F(ElevatorTest, WhenRunningStatusIsSet_GetRunningStatusReturnTheSame)
{
    bool status = true;
    elevator->setRunningStatus(status);
    EXPECT_EQ(elevator->getRunningStatus(), status);
}

TEST_F(ElevatorTest, WhenDestinationFloorIsValid_ThenItReturnsTrue)
{
    EXPECT_TRUE(elevator->isValidDestinationFloor(5));
}

TEST_F(ElevatorTest, WhenDestinationFloorIsInvalid_ThenItReturnsFalse)
{
    EXPECT_FALSE(elevator->isValidDestinationFloor(10));
}

TEST_F(ElevatorTest, WhenLiftIsStopped_ThenItReturnsIdle)
{
    EXPECT_EQ(elevator->stopLift(), Idle);
}

TEST_F(ElevatorTest, WhenCurretnFloorIsGet_ThenItReturnsSameFloor)
{
    int currentFloor = 0;
    EXPECT_EQ(elevator->getCurrentFloor(), currentFloor);
}

TEST_F(ElevatorTest, WhenLiftIsMovedUpFloorIsValid_ThenItReturnsTrue)
{
    std::mutex mutex;
    EXPECT_TRUE(elevator->moveUp(mutex));
}

TEST_F(ElevatorTest, WhenLiftIsMovedUpFloorIsInvalid_ThenItReturnsFalse)
{
    std::mutex mutex;
    elevator = new Elevator(1, Idle, 9);
    EXPECT_FALSE(elevator->moveUp(mutex));
}

TEST_F(ElevatorTest, WhenLiftIsMovedDownFloorISValid_ThenItReturnsTrue)
{
    std::mutex mutex;
    EXPECT_TRUE(elevator->moveDown(mutex));
}

TEST_F(ElevatorTest, WhenLiftIsMOvedDownFloorIsInvalid_ThenItReturnsFalse)
{
    std::mutex mutex;
    elevator = new Elevator(1, Idle, -3);
    EXPECT_FALSE(elevator->moveDown(mutex));
}

TEST_F(ElevatorTest, WhenRequestIsProcessedForUpDirection_ThenItTakesDestinationInputAndReturnsTrue)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillOnce(::testing::Return(1));

    std::mutex mutex;
    elevator = new Elevator(1, LiftUp, 0);
    elevator->addStops(mockRequest, 0);
    std::string inputString = "5\n";
    std::istringstream iss(inputString);

    std::streambuf *originalCin = std::cin.rdbuf();
    std::cin.rdbuf(iss.rdbuf());
    EXPECT_TRUE(elevator->processRequest(mutex));
    std::cin.rdbuf(originalCin);
}

TEST_F(ElevatorTest, WhenRequestIsProcessedForDestination_ThenItReturnsTrue)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillOnce(::testing::Return(1));

    std::mutex mutex;
    elevator = new Elevator(1, LiftUp, 0);
    elevator->addStops(mockRequest, 1);
    EXPECT_TRUE(elevator->processRequest(mutex));
}

TEST_F(ElevatorTest, WhenRequestIsProcessedForDownDirection_ThenItTakesDestinationInputAndReturnsTrue)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillOnce(::testing::Return(6));
    std::mutex mutex;
    elevator = new Elevator(1, LiftDown, 7);
    elevator->addStops(mockRequest, 0);
    std::string inputString = "5\n";
    std::istringstream iss(inputString);

    std::streambuf *originalCin = std::cin.rdbuf();
    std::cin.rdbuf(iss.rdbuf());
    EXPECT_TRUE(elevator->processRequest(mutex));
    std::cin.rdbuf(originalCin);
}

TEST_F(ElevatorTest, WhenRequestIsProcessedForDestination_ThenItReturnsTrue)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillOnce(::testing::Return(6));

    std::mutex mutex;
    elevator = new Elevator(1, LiftDown, 0);
    elevator->addStops(mockRequest, 1);
    EXPECT_TRUE(elevator->processRequest(mutex));
}
