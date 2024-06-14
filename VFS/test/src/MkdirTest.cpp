#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Mkdir.h>
#include <mockFileSystem.h>
#include <mockDirectory.h>

class MkdirTest : public ::testing::Test
{
public:
    Mkdir *mkdir;
    MockFileSystem *mockFileSystem;
    MockDirectory *mockDirectory;
    void SetUp()
    {
        std::string name = "dir1";
        mkdir = new Mkdir(name);
        mockDirectory = new MockDirectory(name);
        mockFileSystem = new MockFileSystem();
    }

    void
    TearDown()
    {
        delete mockFileSystem;
        delete mockDirectory;
        delete mkdir;
    }
};

TEST_F(MkdirTest, WhenExecuteIsCalled_ThenDirectoryIsCreated)
{
    std::string name = "dir1";
    auto rootDirectory = std::make_shared<MockDirectory>("root");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillRepeatedly(::testing::Return(rootDirectory));
    EXPECT_CALL(*rootDirectory, findComponent(name)).WillOnce(::testing::Return(nullptr));
    std::string response = mkdir->execute(*mockFileSystem);
    std::string expectedResponse = "Directory created: " + name + "\n";
    EXPECT_EQ(response, expectedResponse);
}

TEST_F(MkdirTest, WhenExecuteIsCalledAndDirectoryExists_ThenItReturnDirectoryAlreadyExists)
{

    std::string name = "dir1";
    auto rootDirectory = std::make_shared<MockDirectory>("root");
    auto existingDirectory = std::make_shared<MockDirectory>(name);
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(rootDirectory));
    EXPECT_CALL(*rootDirectory, findComponent(name)).WillOnce(::testing::Return(existingDirectory));
    std::string response = mkdir->execute(*mockFileSystem);
    std::string expectedResponse = "Directory already exists: " + name + "\n";
    EXPECT_EQ(response, expectedResponse);
}
