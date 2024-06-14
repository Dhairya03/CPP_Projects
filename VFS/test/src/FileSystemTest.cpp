#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <FileSystem.h>
#include <mockDirectory.h>
#include <mockCommand.h>

class FileSystemTest : public ::testing::Test
{
public:
    FileSystem *fileSystem;
    MockCommand *mockCommand;
    void SetUp()
    {
        auto rootDirectory = std::make_shared<MockDirectory>("root");
        fileSystem = new FileSystem(rootDirectory);
        mockCommand = new MockCommand();
    }

    void TearDown()
    {
        delete mockCommand;
        delete fileSystem;
    }
};

TEST_F(FileSystemTest, WhenCurrentDirectoryIsSet_ThenGetCurrentDirectoryReturnsSame)
{
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    fileSystem->setCurrentDirectory(mockDirectory);
    EXPECT_EQ(mockDirectory, fileSystem->getCurrentDirectory());
}

TEST_F(FileSystemTest, WhenCurrentDirectoryIsSet_ThenGetCurrentDirectoryReturnsDifferent)
{
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    auto differentDirectoyr = std::make_shared<MockDirectory>("different");
    fileSystem->setCurrentDirectory(mockDirectory);
    EXPECT_NE(differentDirectoyr, fileSystem->getCurrentDirectory());
}
