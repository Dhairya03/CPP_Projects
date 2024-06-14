#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "CommandController.h"
#include "mockFileSystem.h"

class CommandControllerTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    CommandController *commandController;
    void SetUp()
    {
        mockFileSystem = new MockFileSystem();
        commandController = new CommandController(mockFileSystem);
    }

    void TearDown()
    {
        delete commandController;
        delete mockFileSystem;
    }
};

TEST_F(CommandControllerTest, WhenValidCommandIsCalledWithvalidCommand_ThenReturnsTrue)
{
    EXPECT_TRUE(commandController->isValidCommand("mkdir"));
}

TEST_F(CommandControllerTest, WhenValidCommandIsCalledWithInvalidCommand_ThenReturnsFalse)
{
    EXPECT_FALSE(commandController->isValidCommand("invalid"));
}

TEST_F(CommandControllerTest, WhenValidArgumentArePasses_ThenItReturnsTrue)
{
    commandController->isValidCommand("mkdir");
    EXPECT_TRUE(commandController->isValidArgument("newDir", ""));
}

TEST_F(CommandControllerTest, WhenInalidArgumentArePassed_ThenItReturnsFalse)
{
    commandController->isValidCommand("mkdir");
    EXPECT_FALSE(commandController->isValidArgument("", ""));
}

TEST_F(CommandControllerTest, ExecuteCommandTest)
{
    std::string command = "mkdir";
    std::string argument1 = "newDir";
    std::string argument2 = "";

    commandController->isValidCommand(command);
    commandController->isValidArgument(argument1, argument2);

    EXPECT_CALL(*mockFileSystem, setCommand(command, argument1, argument2)).Times(1);
    EXPECT_CALL(*mockFileSystem, executeCommand()).WillOnce(::testing::Return("Directory created: newDir\n"));

    commandController->executeCommand();
}

TEST_F(CommandControllerTest, WhenResponseIsSet_ThenGetResponsereturnsSame)
{
    std::string response = "this is the correct response";
    commandController->setResponse(response);
    EXPECT_EQ(response, commandController->getResponse());
}

TEST_F(CommandControllerTest, WhenResponseIsSet_ThenGetResponsereturnsDifferent)
{
    std::string response = "this is the correct response";
    std::string wrongResponse = "This is the wrong response";
    commandController->setResponse(response);
    EXPECT_NE(wrongResponse, commandController->getResponse());
}