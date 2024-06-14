#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Rm.h>
#include <mockFileSystem.h>
#include <mockFile.h>
#include <mockDirectory.h>

class RmTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    Rm *rm;
    void SetUp()
    {
        rm = new Rm("test.txt");
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete rm;
    }
};

TEST_F(RmTest, WhenRmIsCalledAndFileExists_ThenItReturnsFileRemoved)
{
    auto mockFile = std::make_shared<MockFile>("test.txt");
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test.txt")).WillOnce(::testing::Return(mockFile));
    EXPECT_CALL(*mockFile, getType()).WillOnce(::testing::Return("File"));
    EXPECT_CALL(*mockDirectory, removeComponent(mockFile));
    std::string expectedResponse = "File removed: test.txt\n";
    EXPECT_EQ(rm->execute(*mockFileSystem), expectedResponse);
}

TEST_F(RmTest, WhenFileIsNotFound_ThenItReturnsFileNotFound)
{
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test.txt")).WillOnce(::testing::Return(nullptr));
    std::string expectedResponse = "File not found: test.txt\n";
    EXPECT_EQ(rm->execute(*mockFileSystem), expectedResponse);
}

TEST_F(RmTest, WhenRmIsCalledToDeleteDirectory_ItReturnsCannotDeleteADirectory)
{
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    auto testDirectory = std::make_shared<MockDirectory>("test_dir");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test_dir")).WillOnce(::testing::Return(testDirectory));
    EXPECT_CALL(*mockDirectory, getType()).WillOnce(::testing::Return("Directory"));
    std::string expectedResponse = "File not found: test_dir\n";
    EXPECT_EQ(rm->execute(*mockFileSystem), expectedResponse);
}