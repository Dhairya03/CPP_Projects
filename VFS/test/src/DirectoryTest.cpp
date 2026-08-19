#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "Directory.h"

class DirectoryTest : public ::testing::Test
{
public:
    Directory *directory;
    void SetUp()
    {
        std::string name = "Dir1";
        std::shared_ptr<Directory> parent = nullptr;
        directory = new Directory(name, parent);
    }

    void TearDown()
    {
        delete directory;
    }
};

TEST_F(DirectoryTest, WhenGetNameIsCalled_ThenSameNameIsReturned)
{
    std::string name = "Dir1";
    EXPECT_EQ(directory->getName(), name);
}

TEST_F(DirectoryTest, WhenGetNameIsCalled_ThenDifferentNameIsReturned)
{
    std::string name = "dir1";
    EXPECT_NE(directory->getName(), name);
}

TEST_F(DirectoryTest, WhenAddComponentIsCalled_ThenComponentIsAddedToTheDirectory)
{
    auto dir1 = std::make_shared<Directory>("dir1.txt", directory->getParent());
    auto dir2 = std::make_shared<Directory>("dir2.txt", directory->getParent());

    directory->addComponent(dir1);
    directory->addComponent(dir2);

    const auto &components = directory->listComponents();
    EXPECT_EQ(components.size(), 2);
    EXPECT_EQ(components[0]->getName(), "dir1.txt");
    EXPECT_EQ(components[1]->getName(), "dir2.txt");
}

TEST_F(DirectoryTest, WhenRemoveComponentIsCalled_ThenComponentIsRemovedFromTheDirectory)
{
    auto dir1 = std::make_shared<Directory>("dir1.txt", directory->getParent());
    auto dir2 = std::make_shared<Directory>("dir2.txt", directory->getParent());

    directory->addComponent(dir1);
    directory->addComponent(dir2);
    directory->removeComponent(dir1);
    const auto &components = directory->listComponents();
    EXPECT_EQ(components.size(), 1);
    EXPECT_EQ(components[0]->getName(), "dir2.txt");
}

TEST_F(DirectoryTest, WhenFindComponentIsCalled_ThenComponentIsFoundFromTheDirectory)
{
    auto dir1 = std::make_shared<Directory>("dir1.txt", directory->getParent());
    auto dir2 = std::make_shared<Directory>("dir2.txt", directory->getParent());

    directory->addComponent(dir1);
    directory->addComponent(dir2);
    auto found = directory->findComponent("dir1.txt");
    EXPECT_EQ(found, dir1);
}

TEST_F(DirectoryTest, WhenListComponentsIsCalled_ThenComponenetsAreReturnedFromTheDirectory)
{
    auto dir1 = std::make_shared<Directory>("dir1.txt", directory->getParent());
    auto dir2 = std::make_shared<Directory>("dir2.txt", directory->getParent());
    directory->addComponent(dir1);
    directory->addComponent(dir2);

    auto components = directory->listComponents();
    EXPECT_EQ(components, directory->listComponents());
}
