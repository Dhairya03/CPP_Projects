#include <gtest/gtest.h>
#include "trafficSignal.h"

class TrafficSignalTest : public ::testing::Test
{
public:
    TrafficSignal signal;
    // void SetUp()
    // {
    //     signal = new TrafficSignal();
    // }
    // void TearDown()
    // {
    //     delete signal;
    // }
};

TEST_F(TrafficSignalTest, WhenSignalSetToGreen_ThenGetSignalReturnGreen)
{
    signal.setSignal(1);
    EXPECT_EQ(signal.getSignal(), 1);
}

TEST_F(TrafficSignalTest, WhenSignalSetToGreen_ThenGetSignalReturnGreen)
{
    signal.setSignal(1);
    EXPECT_EQ(signal.getSignal(), 1);
}

