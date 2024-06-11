#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <FileSystemComponent.h>

class FileSystemComponentTest : public ::testing::Test
{
public:
    FileSystemComponent *component;
    void SetUp()
    {
        std::string name = "Component";
        component = new FileSystemComponent(name);
    }

    void TearDown()
    {
        delete component;
    }
};

TEST_F(FileSystemComponentTest, WhenGetNameIsCalled_ThenSamenameIsReturned)
{
    std::string name = "Component";
    EXPECT_EQ(component->getName(), name);
}

TEST_F(FileSystemComponentTest, WhenGetNameIsCalled_ThenDifferentNameIsReturned)
{
    std::string name = "WrongComponentName";
    EXPECT_NE(component->getName(), name);
}