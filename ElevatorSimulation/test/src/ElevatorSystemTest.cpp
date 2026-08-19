#include "ElevatorSystem.h"
#include "mockElevator.h"
#include "mockRequest.h"
#include <gtest/gtest.h>

class ElevatorSystemTest : public ::testing::Test
{
public:
    ElevatorSystem *fakeSystem;
    MockElevator *mockElevator1, *mockElevator2;
    MockRequest *mockRequest;
    void SetUp()
    {
        mockElevator1 = new MockElevator();
        mockElevator2 = new MockElevator();
        mockRequest = new MockRequest;
        fakeSystem = new ElevatorSystem(mockElevator1, mockElevator2);
    }

    void TearDown()
    {
        delete mockElevator1;
        delete mockElevator2;
        delete mockRequest;
        delete fakeSystem;
    }
};

TEST_F(ElevatorSystemTest, WhenBothLiftsAreNotRunningNearestIsSecond_ThenAssignedLiftIsSecond)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(0));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    ON_CALL(*mockRequest, getDirection()).WillByDefault(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(7));

    EXPECT_EQ(fakeSystem->findNearestElevator(mockRequest), 2);
}

TEST_F(ElevatorSystemTest, WhenBothLiftsAreNotRunningNearestIsSecond_ThenFarLiftIsNotAssigned)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(0));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    ON_CALL(*mockRequest, getDirection()).WillByDefault(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(6));

    EXPECT_NE(fakeSystem->findNearestElevator(mockRequest), 1);
}

TEST_F(ElevatorSystemTest, WhenBothLiftsAreNotRunningBothAreAtEqualDistance_ThenLiftOneIsAssigned)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(1));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    ON_CALL(*mockRequest, getDirection()).WillByDefault(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(4));

    EXPECT_EQ(fakeSystem->findNearestElevator(mockRequest), 1);
}

TEST_F(ElevatorSystemTest, WhenBothLiftsAreNotRunningNearestIsOne_ThenAssignedLiftIsFirst)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(0));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    ON_CALL(*mockRequest, getDirection()).WillByDefault(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(3));

    EXPECT_EQ(fakeSystem->findNearestElevator(mockRequest), 1);
}

TEST_F(ElevatorSystemTest, WhenFirstIsRunningSecondIsIdleNearestIsSecond_ThenAssignedLiftIsSecond)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(2));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(6));

    EXPECT_EQ(fakeSystem->findNearestElevator(mockRequest), 2);
}

TEST_F(ElevatorSystemTest, WhenFirstIsRunningSecondIsIdleDirectionIsSame_ThenAssignedLiftIsFirst)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(2));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(4));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    EXPECT_EQ(assignedLift, 1);
}

TEST_F(ElevatorSystemTest, WhenFirstIsRunningSecondIsIdleDirectionIsNotSame_ThenAssignedLiftIsSecond)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(2));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(4));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    EXPECT_EQ(assignedLift, 2);
}

TEST_F(ElevatorSystemTest, WhenFirstIsIdleSecondIsRunningClosestIsFirst_ThenAssignedLiftIsFirst)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(5));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(6));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(4));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    EXPECT_EQ(assignedLift, 1);
}

TEST_F(ElevatorSystemTest, WhenFirstIsIdleSecondIsRunningDirectionIsSame_ThenAssignedLiftIsSecond)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(6));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(2));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    EXPECT_EQ(assignedLift, 2);
}

TEST_F(ElevatorSystemTest, WhenFirstIsIdleSecondIsRunningDirectionIsNotSame_ThenAssignedLiftIsSecond)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(false));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(7));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(6));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(2));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    EXPECT_EQ(assignedLift, 1);
}

TEST_F(ElevatorSystemTest, WhenBothRunningBothAboveRequestInSameDirection_ThenFarLiftIsAssigned)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(5));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(4));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(1));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    ASSERT_EQ(assignedLift, 1);
}

TEST_F(ElevatorSystemTest, WhenBothRunningBothBelowRequestInSameDirection_ThenNearLiftIsAssigned)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(1));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(0));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(5));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    ASSERT_EQ(assignedLift, 1);
}

TEST_F(ElevatorSystemTest, WhenRequestIsUpBothRunningOneAboveRequestOneBelowRequest_ThenSameDirectionBelowRequestLiftIsAssigned)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(5));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftUp));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(1));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(2));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    ASSERT_EQ(assignedLift, 2);
}

TEST_F(ElevatorSystemTest, WhenRequestIsDownBothRunningOneAboveRequestOneBelowRequest_ThenSameDirectionAboveRequestLiftIsAssigned)
{
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftDown));
    EXPECT_CALL(*mockElevator1, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(6));

    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(LiftDown));
    EXPECT_CALL(*mockElevator2, getRunningStatus()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(1));

    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(2));

    int assignedLift = fakeSystem->findNearestElevator(mockRequest);

    ASSERT_EQ(assignedLift, 1);
}

TEST_F(ElevatorSystemTest, WhenRequestIsAddedToLiftOne_ThenItReturnsTrue)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Up));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(1));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(0));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator1, addStops(::testing::_, true)).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockElevator2, addStops(::testing::_, ::testing::_)).Times(0);

    EXPECT_TRUE(fakeSystem->addRequest(mockRequest, true));
}

TEST_F(ElevatorSystemTest, WhenRequestIsAddedToLiftTwo_ThenItReturnsTrue)
{
    EXPECT_CALL(*mockRequest, getDirection()).WillRepeatedly(::testing::Return(Down));
    EXPECT_CALL(*mockRequest, getFloor()).WillRepeatedly(::testing::Return(6));
    EXPECT_CALL(*mockElevator1, getCurrentFloor()).WillRepeatedly(::testing::Return(0));
    EXPECT_CALL(*mockElevator2, getCurrentFloor()).WillRepeatedly(::testing::Return(7));
    EXPECT_CALL(*mockElevator1, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));
    EXPECT_CALL(*mockElevator2, getCurrentDirection()).WillRepeatedly(::testing::Return(Idle));

    EXPECT_CALL(*mockElevator1, addStops(::testing::_, ::testing::_)).Times(0);
    EXPECT_CALL(*mockElevator2, addStops(::testing::_, false)).WillOnce(::testing::Return(true));

    EXPECT_TRUE(fakeSystem->addRequest(mockRequest, false));
}
