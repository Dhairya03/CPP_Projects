#include "musicPlayer.h"
#include "mockLibraryWrapper.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MusicPlayerTest : public ::testing::Test
{
public:
    MockLibraryWrapper mockLibrary;
    MusicPlayer player{mockLibrary};
    void SetUp()
    {
        int index = 1;
        player.playPlaylist(index);
    }
};

TEST_F(MusicPlayerTest, WhenPlayPlaylistHasValidIndex_MusicPlays)
{
    int index = 1;

    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).Times(::testing::AtLeast(1));

    EXPECT_TRUE(player.playPlaylist(index));
}

TEST_F(MusicPlayerTest, WhenPlayPlaylistHasInvalidIndex_ReturnsFalse)
{
    int invalidIndex = 0;

    EXPECT_FALSE(player.playPlaylist(invalidIndex));
}

TEST_F(MusicPlayerTest, WhenMusicIsStopped_ThenMusicStops)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));

    EXPECT_TRUE(player.stop());
}

TEST_F(MusicPlayerTest, WhenMusicIsStopped_ThenMusicNotStops)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(false));

    EXPECT_FALSE(player.stop());
}

TEST_F(MusicPlayerTest, WhenMusicIsReplayed_ThenMusicReplays)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));

    EXPECT_TRUE(player.replay());
}

TEST_F(MusicPlayerTest, WhenMusicIsReplayed_ThenMusicNotStopsAndDoesNotReplays)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(false));

    EXPECT_FALSE(player.replay());
}

TEST_F(MusicPlayerTest, WhenMusicIsReplayed_ThenMusicStopsButDoesNotPlayAndDoesNotReplays)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(false));

    EXPECT_FALSE(player.replay());
}

TEST_F(MusicPlayerTest, WhenNextMusicIsPlayed_ThenNextMusicPlays)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));

    EXPECT_TRUE(player.playNextSong());
}

// TEST_F(MusicPlayerTest, WhenPreviousMusicIsPlayed_ThenPreviousMusicPlays)
// {
//     EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));

//     EXPECT_TRUE(player.playPreviousSong());
// }
