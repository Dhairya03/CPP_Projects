#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Ls.h"
#include "Mkdir.h"
#include "mockFileSystem.h"
#include "mockDirectory.h"
#include "mockFileSystemComponent.h"

class LsTest : public ::testing::Test
{
public:
    Ls *ls;
    Mkdir *mkdir;
    MockFileSystem *mockFileSystem;
    MockDirectory *mockDirectory;

    void SetUp()
    {
        std::string name = "dir1";
        ls = new Ls();
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
        delete ls;
    }
};

TEST_F(LsTest, WhenExecuteIsCalled_ThenAllTheComponentsAreListed)
{
    std::string name = "dir1";
    auto mockFile1 = std::make_shared<MockFileSystemComponent>();
    auto rootDirectory = std::make_shared<MockDirectory>("root");
    std::vector<std::shared_ptr<IFileSystemComponent>> components = {mockFile1};
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillRepeatedly(::testing::Return(rootDirectory));
    mkdir->execute(*mockFileSystem);
    EXPECT_CALL(*rootDirectory, listComponents()).WillOnce(::testing::Return(components));
    EXPECT_CALL(*mockFile1, getName()).WillOnce(::testing::Return(name));
    std::string expectedResponse = name + " \n";
    EXPECT_EQ(ls->execute(*mockFileSystem), expectedResponse);
}