#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Find.h"
#include "Ls.h"
#include "Mkdir.h"
#include "mockFileSystem.h"
#include "mockDirectory.h"
#include "mockFileSystemComponent.h"

class FindTest : public ::testing::Test
{
public:
    Find *find;
    Ls *ls;
    Mkdir *mkdir;
    MockFileSystem *mockFileSystem;
    MockDirectory *mockDirectory;

    void SetUp()
    {
        std::string name = "dir1";
        find = new Find(name);
        ls = new Ls();
        mkdir = new Mkdir(name);
        mockDirectory = new MockDirectory(name);
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete mockDirectory;
        delete mkdir;
        delete ls;
        delete find;
    }
};

TEST_F(FindTest, WhenExecuteIsCalledAndFileExists_ThenItReturndsFound)
{
    std::string name = "dir1";
    auto rootDirectory = std::make_shared<MockDirectory>("root");
    auto mockFile1 = std::make_shared<MockFileSystemComponent>();
    std::vector<std::shared_ptr<IFileSystemComponent>> components = {mockFile1};
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillRepeatedly(::testing::Return(rootDirectory));
    mkdir->execute(*mockFileSystem);
    EXPECT_CALL(*rootDirectory, listComponents()).WillOnce(::testing::Return(components));
    EXPECT_CALL(*mockFile1, getName()).WillRepeatedly(::testing::Return(name));
    EXPECT_CALL(*rootDirectory, getName()).WillRepeatedly(::testing::Return("root"));
    std::string expectedResponse = "Found: " + name + " in " + "root" + "\n";
    EXPECT_EQ(find->execute(*mockFileSystem), expectedResponse);
}

TEST_F(FindTest, WhenExecuteIsCalledAndFileDoesNotExist_ThenItReturnsNotFound)
{
    std::string nonExistingFileName = "wrongDirectory";
    find = new Find(nonExistingFileName);
    std::string name = "dir1";
    auto rootDirectory = std::make_shared<MockDirectory>("root");
    auto mockFile1 = std::make_shared<MockFileSystemComponent>();
    std::vector<std::shared_ptr<IFileSystemComponent>> components = {mockFile1};
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillRepeatedly(::testing::Return(rootDirectory));
    mkdir->execute(*mockFileSystem);
    EXPECT_CALL(*rootDirectory, listComponents()).WillOnce(::testing::Return(components));
    EXPECT_CALL(*mockFile1, getName()).WillRepeatedly(::testing::Return(name));
    EXPECT_CALL(*rootDirectory, getName()).WillRepeatedly(::testing::Return("root"));
    std::string expectedResponse = nonExistingFileName + "not found.\n";
    EXPECT_EQ(find->execute(*mockFileSystem), expectedResponse);
}