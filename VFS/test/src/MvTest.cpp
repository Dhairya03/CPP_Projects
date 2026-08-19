#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Mv.h"
#include "mockFileSystem.h"
#include "mockFile.h"
#include "mockDirectory.h"
#include "mockFileSystemComponent.h"

class MvTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    Mv *mv;
    void SetUp()
    {
        mv = new Mv("test.txt", "dir1");
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete mv;
    }
};

TEST_F(MvTest, WhenMovingToDestinationThatIsExisting_ThenItReturnsMovedToDestination)
{
    auto mockCurrentDirectory = std::make_shared<MockDirectory>("dir1");
    auto mockComponent = std::make_shared<MockFileSystemComponent>();
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockCurrentDirectory));
    EXPECT_CALL(*mockCurrentDirectory, findComponent("test.txt")).WillOnce(::testing::Return(mockComponent));
    EXPECT_CALL(*mockCurrentDirectory, removeComponent(std::dynamic_pointer_cast<IFileSystemComponent>(mockComponent)));
    EXPECT_CALL(*mockCurrentDirectory, findComponent("dir1")).WillOnce(::testing::Return(std::dynamic_pointer_cast<IDirectory>(mockCurrentDirectory)));
    EXPECT_CALL(*mockCurrentDirectory, addComponent(std::dynamic_pointer_cast<IFileSystemComponent>(mockComponent)));
    std::string expectedResponse = "Moved test.txt to dir1\n";
    EXPECT_EQ(mv->execute(*mockFileSystem), expectedResponse);
}

TEST_F(MvTest, WhenSourceIsNotFound_ThenItReturnsDirectoryNotFound)
{
    auto mockCurrentDirectory = std::make_shared<MockDirectory>("dir1");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockCurrentDirectory));
    EXPECT_CALL(*mockCurrentDirectory, findComponent("test.txt")).WillOnce(::testing::Return(nullptr));
    std::string expectedResponse = "File/Directory not found: test.txt\n";
    EXPECT_EQ(mv->execute(*mockFileSystem), expectedResponse);
}