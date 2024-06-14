#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <Mv.h>
#include <mockFileSystem.h>
#include <mockFile.h>
#include <mockDirectory.h>

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

TEST_F(MvTest, WhenMovingToDestinationThatIsExistin_ThenItReturnsMovedToDestination)
{
    auto mockCurrentDirectory = std::make_shared<MockDirectory>();
    auto mockComponent = std::make_shared<MockComponent>();
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(mockCurrentDirectory));
    EXPECT_CALL(*mockCurrentDirectory, findComponent("source")).WillOnce(::testing::Return(mockComponent));
    EXPECT_CALL(*mockComponent, getName()).WillOnce(::testing::Return("source"));
    EXPECT_CALL(*mockCurrentDirectory, removeComponent(mockComponent));
    EXPECT_CALL(*mockCurrentDirectory, findComponent("destination")).WillOnce(::testing::Return(std::static_pointer_cast<Component>(mockCurrentDirectory)));
    EXPECT_CALL(*mockCurrentDirectory, addComponent(mockComponent));
    std::string expectedResponse = "Moved source to destination\n";
    EXPECT_EQ(mv->execute(*mockFileSystem), expectedResponse);
}

TEST_F(MvTest, WhenSourceIsNotFound_ThenItReturnsDirectoryNotFound)
{
    EXPECT_CALL(*mockFileSystem, getCurrentDirectory()).WillOnce(::testing::Return(nullptr));
    std::string expectedResponse = "File/Directory not found: source\n";
    EXPECT_EQ(mv->execute(*mockFileSystem), expectedResponse);
}