#include "musicPlayer.h"
#include "mockLibraryWrapper.h"
#include "ISong.h"
#include "mockSong.h"
#include "mockPlaylist.h"
#include "IPlaylist.h"

#include <gmock/gmock.h>
#include <gtest/gtest.h>

class MusicPlayerTest : public ::testing::Test
{
public:
    MockLibraryWrapper mockLibrary;
    std::vector<IPlaylist *> mockPlaylists;
    std::vector<ISong *> mockSongs;
    IPlaylist *playlist;
    ISong *song;
    MusicPlayer *player;
    MockPlaylist *mockPlaylist;
    MockSong *mockSong;

    void addMockSong()
    {
        mockPlaylist->addSong(mockSong);
    }

    void addMockPlaylist()
    {
        mockPlaylists.push_back(mockPlaylist);
    }
    void SetUp()
    {
        mockSong = new MockSong();
        mockPlaylist = new MockPlaylist();
        playlist = mockPlaylist;
        song = mockSong;
        // mockPlaylists.push_back(mockPlaylist);
        // mockPlaylist->addSong(mockSong);
        addMockPlaylist();
        addMockSong();
        player = new MusicPlayer(mockLibrary, mockPlaylists, mockSongs);
    }
    void TearDown()
    {
        delete mockSong;
        delete mockPlaylist;
        delete player;
    }
};

TEST_F(MusicPlayerTest, WhenPlayPlaylistHasValidIndex_MusicPlays)
{
    int index = 1;
    EXPECT_CALL(*mockPlaylist, getSongs()).WillOnce(::testing::Return(std::vector<ISong *>(1, mockSong)));
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).Times(::testing::AtLeast(1));
    EXPECT_TRUE(player->playPlaylist(index));
}

TEST_F(MusicPlayerTest, WhenPlayPlaylistHasInvalidIndex_ReturnsFalse)
{
    int invalidIndex = 0;

    EXPECT_FALSE(player->playPlaylist(invalidIndex));
}

TEST_F(MusicPlayerTest, WhenMusicIsStopped_ThenMusicStops)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));

    EXPECT_TRUE(player->stop());
}

TEST_F(MusicPlayerTest, WhenMusicIsStopped_ThenMusicNotStops)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(false));

    EXPECT_FALSE(player->stop());
}

TEST_F(MusicPlayerTest, WhenMusicIsReplayed_ThenMusicReplays)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));

    EXPECT_TRUE(player->replay());
}

TEST_F(MusicPlayerTest, WhenMusicIsReplayed_ThenMusicNotStopsAndDoesNotReplays)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(false));

    EXPECT_FALSE(player->replay());
}

TEST_F(MusicPlayerTest, WhenMusicIsReplayed_ThenMusicStopsButDoesNotPlayAndDoesNotReplays)
{
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(false));

    EXPECT_FALSE(player->replay());
}

TEST_F(MusicPlayerTest, WhenMusicIsTogglePausedAndMusicIsPlaying_ThenMusicPauses)
{
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, pause()).WillOnce(::testing::Return(true));
    player->playSong(mockSong);
    EXPECT_TRUE(player->togglePause());
}

TEST_F(MusicPlayerTest, WhenMusicIsTogglePausedAndMusicIsPaused_ThenMusicPlays)
{
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(false));
    player->playSong(mockSong);
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));

    EXPECT_FALSE(player->togglePause());
}

TEST_F(MusicPlayerTest, WhenMusicIsTogglePausedAndMusicIsPlaying_ThenMusicDoesNotPauses)
{
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, pause()).WillOnce(::testing::Return(false));
    player->playSong(mockSong);
    EXPECT_FALSE(player->togglePause());
}

TEST_F(MusicPlayerTest, WhenMusicIsTogglePausedAndMusicIsPaused_ThenMusicDoesNotPlays)
{
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(false));
    player->playSong(mockSong);
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(false));

    EXPECT_TRUE(player->togglePause());
}

TEST_F(MusicPlayerTest, WhenGivenSongFileIsOpened_ThenMusicPlays)
{
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));
    EXPECT_TRUE(player->playSong(mockSong));
}

TEST_F(MusicPlayerTest, WhenGivenSongFileIsNotOpened_ThenMusicNotPlays)
{
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(false));
    EXPECT_FALSE(player->playSong(mockSong));
}

TEST_F(MusicPlayerTest, WhenPlaylistNotExists_ThenNextSongNotPlays)
{
    player->playPlaylist(0);
    EXPECT_FALSE(player->playNextSong());
}

TEST_F(MusicPlayerTest, WhenPlaylistExistsCurrentSongIsLast_ThenNextSongNotPlays)
{
    EXPECT_CALL(*mockPlaylist, getSongs()).WillRepeatedly(::testing::Return(std::vector<ISong *>(1, mockSong)));
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));
    player->playPlaylist(1);
    EXPECT_FALSE(player->playNextSong());
}

TEST_F(MusicPlayerTest, WhenPlaylistExistsNextSongExists_ThenNextSongPlays)
{
    addMockSong();
    EXPECT_CALL(*mockPlaylist, getSongs()).WillOnce(::testing::Return(std::vector<ISong *>(1, mockSong))).WillRepeatedly(::testing::Return(std::vector<ISong *>(2, mockSong)));
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(mockLibrary, stop()).WillOnce(::testing::Return(true));
    player->playPlaylist(1);
    EXPECT_TRUE(player->playNextSong());
}

TEST_F(MusicPlayerTest, WhenPlaylistNotExists_ThenPreviousSongNotPlays)
{
    player->playPlaylist(0);
    EXPECT_FALSE(player->playPreviousSong());
}

TEST_F(MusicPlayerTest, WhenPlaylistExistsCurrentSongIsFirst_ThenPreviousSongNotPlays)
{
    EXPECT_CALL(*mockPlaylist, getSongs()).WillRepeatedly(::testing::Return(std::vector<ISong *>(1, mockSong)));
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillOnce(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillOnce(::testing::Return(true));
    player->playPlaylist(1);
    EXPECT_FALSE(player->playPreviousSong());
}

TEST_F(MusicPlayerTest, WhenPlaylistExistsPreviousSongExists_ThenPreviousSongPlays)
{
    addMockSong();
    EXPECT_CALL(*mockPlaylist, getSongs()).WillOnce(::testing::Return(std::vector<ISong *>(1, mockSong))).WillRepeatedly(::testing::Return(std::vector<ISong *>(2, mockSong)));
    EXPECT_CALL(mockLibrary, openFromFile(::testing::_)).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(mockLibrary, play()).WillRepeatedly(::testing::Return(true));
    EXPECT_CALL(mockLibrary, stop()).WillRepeatedly(::testing::Return(true));
    player->playPlaylist(1);
    player->playNextSong();
    EXPECT_TRUE(player->playPreviousSong());
}
