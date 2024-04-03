#include <gtest/gtest.h>
#include "lane.h"
#include "mockTrafficSignal.h"

class LaneTest : public ::testing::Test
{
public:
    MockTrafficSignal mockSignal;
    Lane lane{&mockSignal};
};

TEST_F(LaneTest, WhenCounterSetsValidvalue_ThenGetCounterReturnsSameValue)
{
    EXPECT_CALL(mockSignal, getSignal).WillOnce(::testing::Return(1));
    lane.setCounter(&mockSignal);
    EXPECT_EQ(lane.getCounter(), 1);
}

TEST_F(LaneTest, WhenLoopStartIsTrueThenItReturnsTrue)
{
    lane.setLoopStart(true);
    EXPECT_TRUE(lane.getLoopStart());
}