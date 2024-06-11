#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <File.h>

class FileTest : public ::testing::Test
{
public:
    File *file;
    void SetUp()
    {
        std::string name = "abc.txt";
        file = new File(name);
    }

    void TearDown()
    {
        delete file;
    }
};

TEST_F(FileTest, WhenContentIsSet_ThenGetContentReturnsSameData)
{
    std::string content = "Hi I am the content of this file";
    file->setContent(content);
    EXPECT_EQ(file->getContent(), content);
}

TEST_F(FileTest, WhenContentIsSet_ThenGetContentReturnDifferentData)
{
    std::string content = "Hi I am the entered content in the file";
    std::string wrongContent = "This is not the content of file";

    file->setContent(wrongContent);
    EXPECT_NE(file->getContent(), content);
}