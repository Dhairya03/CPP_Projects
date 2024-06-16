#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Cd.h"
#include "mockFileSystem.h"
#include "mockFile.h"
#include "mockDirectory.h"
#include "mockFileSystemComponent.h"

class CdTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    Cd *cd;
    void SetUp()
    {
        cd = new Cd("sub_directory");
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
    auto mockDirectory = std::make_shared<MockDirectory>("directory");
    auto subDirectory = std::make_shared<MockDirectory>("sub_directory");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("sub_directory")).WillOnce(::testing::Return(subDirectory));
    EXPECT_CALL(*subDirectory, getType()).WillOnce(::testing::Return("Directory"));
    EXPECT_CALL(*mockFileSystem, setCurrentDirectory(std::dynamic_pointer_cast<IDirectory>(subDirectory)));
    EXPECT_CALL(*subDirectory, getName()).WillOnce(::testing::Return("sub_directory"));
    std::string expectedResponse = "Changed to directory: sub_directory\n";
    EXPECT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}

TEST_F(CdTest, WHenMovingToParentDirectory_ThenItReturnsParentDirectory)
{
    auto mockCurrentDirectory = std::make_shared<MockDirectory>("currentDirectory");
    cd = new Cd("..");
    auto mockParentDirectory = std::make_shared<MockDirectory>("parent_directory");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockCurrentDirectory));
    EXPECT_CALL(*mockCurrentDirectory, getParent()).WillOnce(::testing::Return(mockParentDirectory));
    EXPECT_CALL(*mockFileSystem, setCurrentDirectory(std::dynamic_pointer_cast<IDirectory>(mockParentDirectory)));
    EXPECT_CALL(*mockParentDirectory, getName()).WillOnce(::testing::Return("parent_directory"));
    std::string expectedResponse = "Changed to directory: parent_directory\n";
    EXPECT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}

TEST_F(CdTest, WhenPathIsNotFound_ThenItReturnsDirectoryNotFound)
{
    auto mockDirectory = std::make_shared<MockDirectory>("directory");
    auto subDirectory = std::make_shared<MockDirectory>("sub_directory");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("sub_directory")).WillOnce(::testing::Return(mockDirectory));
    std::string expectedResponse = "Directory not found: sub_directory\n";
    EXPECT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}

TEST_F(CdTest, WhenPathIsFoundButItIsNotADirectory_ThenItReturnsDirectoryNotFound)
{
    cd = new Cd("mockFile");
    auto mockDirectory = std::make_shared<MockDirectory>("directory");
    auto mockFile = std::make_shared<MockFile>("mockFile");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent("mockFile")).WillOnce(::testing::Return(mockFile));
    EXPECT_CALL(*mockFile, getType()).WillOnce(::testing::Return("File"));
    std::string expectedResponse = "Directory not found: mockFile\n";
    EXPECT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}

TEST_F(CdTest, WhenPathIsEmpty_ThenItReturnsInvalidPath)
{
    cd = new Cd("");
    auto mockDirectory = std::make_shared<MockDirectory>("directory");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    std::string expectedResponse = "Invalid path\n";
    EXPECT_EQ(cd->execute(*mockFileSystem), expectedResponse);
}