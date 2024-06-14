#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Cd.h>
#include <mockFileSystem.h>
#include <mockFile.h>
#include <mockDirectory.h>
#include <mockFileSystemComponent.h>

class CdTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    Cd *cd;
    void SetUp()
    {
        cd = new Cd("dir1");
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete cd;
    }
};

TEST_F(CdTest, WhenMovingToExistingDirectory_ThenItReturnsChangedDirectory)
{
    auto mockDirectory = std::make_shared<MockDirectory>();
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("path")).WillOnce(::testing::Return(std::static_pointer_cast<MockFileSystemComponent>(mockDirectory)));
    EXPECT_CALL(*mockDirectory, findComponent("to")).WillOnce(::testing::Return(std::static_pointer_cast<MockFileSystemComponent>(mockDirectory)));
    EXPECT_CALL(*mockDirectory, findComponent("directory")).WillOnce(::testing::Return(std::static_pointer_cast<MockFileSystemComponent>(mockDirectory)));
    EXPECT_CALL(*mockFileSystem, setCurrentDirectory(mockDirectory));
    std::string expectedResponse = "Changed to directory: directory\n";
    EXPECT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}

TEST_F(CdTest, WHenMovingToParentDirectory_ThenItReturnsParentDirectory)
{
    auto mockCurrentDirectory = std::make_shared<MockDirectory>();
    auto mockParentDirectory = std::make_shared<MockDirectory>();
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockCurrentDirectory));
    EXPECT_CALL(*mockCurrentDirectory, getParent()).WillOnce(::testing::Return(mockParentDirectory));
    EXPECT_CALL(*mockFileSystem, setCurrentDirectory(mockParentDirectory));
    std::string expectedResponse = "Changed to directory: parent_directory\n";
    EXPECT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}

TEST_F(CdTest, WhenPathIsNotFound_ThenItReturnsDirectoryNotFound)
{
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(nullptr));
    std::string expectedResponse = "Directory not found: path\n";
    EXEPCT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}