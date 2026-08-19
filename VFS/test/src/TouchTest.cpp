#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Touch.h"
#include "mockFileSystem.h"
#include "mockFile.h"
#include "mockDirectory.h"

class TouchTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    Touch *touch;
    void SetUp()
    {
        touch = new Touch("test.txt");
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete touch;
    }
};

TEST_F(TouchTest, WhenNewFileIsCreated_ThenItReturnsNewFileCreated)
{
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test.txt")).WillOnce(::testing::Return(nullptr));
    EXPECT_CALL(*mockDirectory, addComponent(::testing::_));
    std::string expectedResponse = "New file created: test.txt\n";
    EXPECT_EQ(touch->execute(*mockFileSystem), expectedResponse);
}

TEST_F(TouchTest, WhenFileAlreadyExists_ThenItReturnsFileAlreadyExists)
{
    auto mockFile = std::make_shared<MockFile>("mockFile");
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test.txt")).WillOnce(::testing::Return(mockFile));
    std::string expectedResponse = "File already exists: test.txt\n";
    EXPECT_EQ(touch->execute(*mockFileSystem), expectedResponse);
}
