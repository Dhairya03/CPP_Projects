#include "musicPlayer.h"
#include "mockLibraryWrapper.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MusicPlayerTest : public ::testing::Test
{
public:
    MockLibraryWrapper mockLibrary;
    MusicPlayer player{mockLibrary};
};

TEST_F(MusicPlayerTest, WhenPlayPlaylistHasValidIndex_MusicPlays)
{
    int index = 1;
    
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).Times(::testing::AtLeast(1));

    bool result = player.playPlaylist(index);

    ASSERT_TRUE(result);
}

TEST_F(MusicPlayerTest, WhenPlayPlaylistHasInvalidIndex_ReturnsFalse)
{
    int invalidIndex = 0;

    bool result = player.playPlaylist(invalidIndex);

    ASSERT_FALSE(result);
}