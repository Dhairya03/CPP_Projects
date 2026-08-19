#include "FileParser.h"
#include "mockParser.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>
class ParseTest : public ::testing::Test
{
public:
    MockParser mockParser;
    FileParser parser{&mockParser};
};

TEST_F(ParseTest, WhenFileOpensParsingSuccess_ThenFileSuccessfullyParsed)
{
    EXPECT_CALL(mockParser, openFile).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockParser, parseFile).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockParser, printFileData).WillOnce(::testing::Return());
    EXPECT_CALL(mockParser, closeFile).WillOnce(::testing::Return(true));
    EXPECT_TRUE(parser.parse());
}

TEST_F(ParseTest, WhenFileOpensParsingFails_ThenFileNotParsed)
{
    EXPECT_CALL(mockParser, openFile).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockParser, parseFile).WillOnce(::testing::Return(false));
    EXPECT_CALL(mockParser, closeFile).WillOnce(::testing::Return(true));
    EXPECT_FALSE(parser.parse());
}

TEST_F(ParseTest, WhenFileNotOpens_ThenFileNotParsed)
{
    EXPECT_CALL(mockParser, openFile).WillOnce(::testing::Return(false));
    EXPECT_FALSE(parser.parse());
}



