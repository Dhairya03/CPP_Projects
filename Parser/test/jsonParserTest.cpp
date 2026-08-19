#include "jsonParser.h"
#include "mockStream.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class JsonParserTest : public ::testing::Test
{
public:
    MockStream mockStream;
    JsonParser jsonParser{&mockStream};
};

TEST_F(JsonParserTest, WhenFileOpens_ThenReturnTrue)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(true));
    EXPECT_TRUE(jsonParser.openFile());
}

TEST_F(JsonParserTest, WhenFileNotOpens_ThenReturnFalse)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(false));
    EXPECT_ANY_THROW(jsonParser.openFile());
}

TEST_F(JsonParserTest, WhenFileCloses_ThenReturnTrue)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(false));
    EXPECT_TRUE(jsonParser.closeFile());
}

TEST_F(JsonParserTest, WhenFileNotCloses_ThenReturnFalse)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(true));
    EXPECT_ANY_THROW(jsonParser.closeFile());
}