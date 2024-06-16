#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Rmdir.h"
#include "mockFileSystem.h"
#include "mockDirectory.h"
#include "mockFileSystemComponent.h"
#include "mockFile.h"

class RmdirTest : public ::testing::Test
{
public:
    Rmdir *rmdir;
    MockFileSystem *mockFileSystem;
    MockDirectory *mockDirectory;
    void SetUp()
    {
        std::string name = "test_dir";
        rmdir = new Rmdir(name);
        mockDirectory = new MockDirectory(name);
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete mockDirectory;
        delete rmdir;
    }
};

TEST_F(RmdirTest, WhenRemoveDirectoryThatIsExistingAndEmpty_ThenItReturnsDirectoryRemoved)
{
    auto rootDirectory = std::make_shared<MockDirectory>("root");
    auto mockDirectory = std::make_shared<MockDirectory>("test_dir");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(rootDirectory));
    EXPECT_CALL(*rootDirectory, findComponent("test_dir")).WillOnce(::testing::Return(mockDirectory));
    // EXPECT_CALL(*mockDirectory, listComponents()).WillOnce(::testing::Return(std::vector<std::shared_ptr<MockFileSystemComponent>>{mockComponent}));
    EXPECT_CALL(*rootDirectory, removeComponent(std::dynamic_pointer_cast<IFileSystemComponent>(mockDirectory)));
    std::string expectedResponse = "Directory removed: test_dir\n";
    EXPECT_EQ(rmdir->execute(*mockFileSystem), expectedResponse);
}

TEST_F(RmdirTest, DirectoryNotFound)
{
    auto mockDirectory = std::make_shared<MockDirectory>("dir1");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test_dir")).WillOnce(::testing::Return(nullptr));
    std::string expectedResponse = "Directory not found: test_dir\n";
    EXPECT_EQ(rmdir->execute(*mockFileSystem), expectedResponse);
}

TEST_F(RmdirTest, WhenPathIsNotADirectory_ThenItreturnsNotADirectory)
{
    auto mockDirectory = std::make_shared<MockDirectory>("dir1");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    auto mockFile = std::make_shared<MockFile>("test_dir");
    EXPECT_CALL(*mockDirectory, findComponent("test_dir")).WillOnce(::testing::Return(mockFile));
    std::string expectedResponse = "Path is not a directory: test_dir\n";
    EXPECT_EQ(rmdir->execute(*mockFileSystem), expectedResponse);
}

TEST_F(RmdirTest, WhenDirectoryIsNotEmpty_ItReturnsDirectoryNotEmpty)
{
    auto mockDirectory = std::make_shared<MockDirectory>("dir1");
    auto testDirectory = std::make_shared<MockDirectory>("test_dir");
    auto mockFile = std::make_shared<MockFile>("mockFile");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test_dir")).WillOnce(::testing::Return(testDirectory));
    EXPECT_CALL(*testDirectory, listComponents()).WillOnce(::testing::Return(std::vector<std::shared_ptr<IFileSystemComponent>>{std::dynamic_pointer_cast<IFileSystemComponent>(mockFile)}));
    std::string expectedResponse = "Directory is not empty: test_dir\n";
    EXPECT_EQ(rmdir->execute(*mockFileSystem), expectedResponse);
}
