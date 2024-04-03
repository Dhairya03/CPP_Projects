#include <gtest/gtest.h>
#include "lane.h"

class LaneTest : public ::testing::Test
{
public:
    Lane *lane;
};

TEST_F(LaneTest, WhenCounterSetsValidvalue_ThenGetCounterReturnsSameValue)
{
    lane->setCounter();
    EXPECT_EQ(lane->getCounter(), 1);
}