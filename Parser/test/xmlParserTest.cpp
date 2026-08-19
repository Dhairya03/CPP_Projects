#include "xmlParser.h"
#include "mockStream.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class XmlParserTest : public ::testing::Test
{
public:
    MockStream mockStream;
    XmlParser xmlParser{&mockStream};
};

TEST_F(XmlParserTest, WhenFileOpens_ThenReturnTrue)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(true));
    EXPECT_TRUE(xmlParser.openFile());
}

TEST_F(XmlParserTest, WhenFileNotOpens_ThenReturnFalse)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(false));
    EXPECT_ANY_THROW(xmlParser.openFile());
}

TEST_F(XmlParserTest, WhenFileCloses_ThenReturnTrue)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(false));
    EXPECT_TRUE(xmlParser.closeFile());
}

TEST_F(XmlParserTest, WhenFileNotCloses_ThenReturnFalse)
{
    EXPECT_CALL(mockStream, is_open).WillOnce(::testing::Return(true));
    EXPECT_ANY_THROW(xmlParser.closeFile());
}