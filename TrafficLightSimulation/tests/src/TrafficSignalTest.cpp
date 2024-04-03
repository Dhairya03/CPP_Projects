#include <gtest/gtest.h>
#include "trafficSignal.h"

class TrafficSignalTest : public ::testing::Test
{
public:
    TrafficSignal signal;
};

TEST_F(TrafficSignalTest, WhenSignalSetToGreen_ThenGetSignalReturnGreen)
{
    signal.setSignal(1);
    EXPECT_EQ(signal.getSignal(), 1);
}
