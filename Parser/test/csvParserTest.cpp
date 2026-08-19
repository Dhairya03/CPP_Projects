#include "csvParser.h"
#include "mockStream.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class CsvParserTest : public ::testing::Test
{
public:
    MockStream mockStream;
    CsvParser csvParser{&mockStream};
};

TEST_F(CsvParserTest, WhenFileOpens_ThenReturnTrue)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(true));
    EXPECT_TRUE(csvParser.openFile());
}

TEST_F(CsvParserTest, WhenFileNotOpens_ThenReturnFalse)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(false));
    EXPECT_ANY_THROW(csvParser.openFile());
}

TEST_F(CsvParserTest, WhenFileCloses_ThenReturnTrue)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(false));
    EXPECT_TRUE(csvParser.closeFile());
}

TEST_F(CsvParserTest, WhenFileNotCloses_ThenReturnFalse)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(true));
    EXPECT_ANY_THROW(csvParser.closeFile());
}