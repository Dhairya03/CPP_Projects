#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "mockCommandController.h"
#include "CommandParser.h"

class CommandParserTest : public ::testing::Test
{
public:
    CommandParser *parser;
    MockCommandController *mockController;
    void SetUp()
    {
        mockController = new MockCommandController();
        parser = new CommandParser(mockController);
    }
    void TearDown()
    {
        delete mockController;
        delete parser;
    }
};

TEST_F(CommandParserTest, WhenValidCommandAndArgumentsArePassed_ThenItReturnsTrue)
{
    std::string input = "command arg1 arg2";
    auto tokens = parser->parseRequest(input);
    EXPECT_CALL(*mockController, isValidCommand(tokens[0])).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockController, isValidArgument(tokens[1], tokens[2])).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockController, executeCommand());
    EXPECT_TRUE(parser->validateCommand(tokens));
}

TEST_F(CommandParserTest, WhenInvalidCommandIsPasses_ThenItReturnFalse)
{
    std::string input = "invalid_command";
    auto tokens = parser->parseRequest(input);
    EXPECT_CALL(*mockController, isValidCommand(tokens[0])).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mockController, isValidArgument(::testing::_, ::testing::_)).Times(0);
    EXPECT_CALL(*mockController, executeCommand()).Times(0);
    EXPECT_FALSE(parser->validateCommand(tokens));
}

TEST_F(CommandParserTest, WhenInvalidArgumentsArePassed_ThenItReturnFalse)
{
    std::string input = "command invalid_arg1 invalid_arg2";
    auto tokens = parser->parseRequest(input);
    EXPECT_CALL(*mockController, isValidCommand(tokens[0])).WillOnce(::testing::Return(true));
    EXPECT_CALL(*mockController, isValidArgument(tokens[1], tokens[2])).WillOnce(::testing::Return(false));
    EXPECT_CALL(*mockController, executeCommand()).Times(0);
    EXPECT_FALSE(parser->validateCommand(tokens));
}
