#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Cat.h>
#include <mockFileSystem.h>
#include <mockFile.h>
#include <mockDirectory.h>

class CatTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    Cat *cat;
    void SetUp()
    {
        cat = new Cat("test.txt");
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete cat;
    }
};

TEST_F(CatTest, WhenReadingExistingFile_ThenItReturnsTheContentofFile)
{
    auto mockFile = std::make_shared<MockFile>();
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test.txt")).WillOnce(::testing::Return(mockFile));
    EXPECT_CALL(*mockFile, getContent()).WillOnce(::testing::Return("File content"));
    std::string expectedResponse = "File contents of test.txt: File content\n";
    EXPECT_EQ(cat->execute(*mockFileSystem), expectedResponse);
}

TEST_F(CatTest, WhenFileIsNotFound_ThenItReturnsFileNotFound)
{
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("test.txt")).WillOnce(::testing::Return(nullptr));
    std::string expectedResponse = "File not found: test.txt\n";
    EXPECT_EQ(cat->execute(*mockFileSystem), expectedResponse);
}
