#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Vi.h>
#include <mockFileSystem.h>
#include <mockFile.h>
#include <mockDirectory.h>

class ViTest : public ::testing::Test
{
public:
    MockFileSystem *mockFileSystem;
    Vi *vi;
    void SetUp()
    {
        vi = new Vi("test.txt", "Initial content");
        mockFileSystem = new MockFileSystem();
    }

    void TearDown()
    {
        delete mockFileSystem;
        delete vi;
    }
};

TEST_F(ViTest, WhenNewFileIsCreated_ThenTheDataIsSetToFileCOntent)
{
    std::string fileName = "test.txt";
    auto mockDirectory = std::make_shared<MockDirectory>("mock");
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockDirectory));
    EXPECT_CALL(*mockDirectory, findComponent(fileName)).WillOnce(::testing::Return(nullptr));
    EXPECT_CALL(*mockDirectory, addComponent(::testing::_));
    std::string expectedResponse = "New file created: " + fileName + "\n";
    expectedResponse += "Data saved to file: " + fileName + "\n";
    EXPECT_EQ(vi->execute(*mockFileSystem), expectedResponse);
}

TEST_F(ViTest, WhenExitWithoutCreatingFile_ThenFileIsNotCreated)
{
    vi = new Vi("test.txt", "q");
    std::string expectedResponse = "File not created \n";
    EXPECT_EQ(vi->execute(*mockFileSystem), expectedResponse);
}