#include "playlist.h"
#include "song.h"
#include <gtest/gtest.h>
#include <gmock/gmock.h>

class PlaylistTest : public ::testing::Test
{
public:
    Playlist *playlist;
    ISong *song;
    std::string songTitle = "/home/dhairyagupta/songs/guitar.wav";
    std::string playlistName = "testPlay";
    void SetUp()
    {
        playlist = new Playlist(playlistName);
        song = new Song(songTitle);
        playlist->addSong(song);
    }
    void TearDown()
    {
        delete song;
        delete playlist;
    }
};

TEST_F(PlaylistTest, WhenSongIsAdded_ThenReturnTrue)
{
    EXPECT_TRUE(playlist->addSong(song));
}

TEST_F(PlaylistTest, WhenGetNameIsCalled_ThenReturnPlaylistName)
{
    EXPECT_EQ(playlist->getName(), name);
}

TEST_F(PlaylistTest, WhenSongIsDeletedValidIndex_ThenReturnsTrue)
{
    int index = 0;
    EXPECT_TRUE(playlist->deleteSong(index));
}

TEST_F(PlaylistTest, WhenSongIsDeletedInValidIndex_ThenReturnsFalse)
{
    int invalidIndex = -1;
    EXPECT_FALSE(playlist->deleteSong(invalidIndex));
}

TEST_F(PlaylistTest, WhenSongNameIsUpdated_ThenReturnsTrue)
{
    std::string newName = "newTestPlay";
    EXPECT_TRUE(playlist->updatePlaylistName(newName));
}

TEST_F(PlaylistTest, WhenSongIsMovedUpValidIndex_ThenReturnsTrue)
{
    int index = 1;
    ISong *newSong = new Song("song.wav");
    playlist->addSong(newSong);
    EXPECT_TRUE(playlist->moveSongUp(index));
}

TEST_F(PlaylistTest, WhenSongIsMovedUpInValidIndex_ThenReturnsFalse)
{
    int index = -1;
    ISong *newSong = new Song("song.wav");
    playlist->addSong(newSong);
    EXPECT_FALSE(playlist->moveSongUp(index));
}

TEST_F(PlaylistTest, WhenSongIsMovedUpInsufficientSize_ThenReturnsFalse)
{
    int index = 2;
    ISong *newSong = new Song("song.wav");
    playlist->addSong(newSong);
    EXPECT_FALSE(playlist->moveSongUp(index));
}

TEST_F(PlaylistTest, WhenSongIsMovedDownValidIndex_ThenReturnsTrue)
{
    int index = 0;
    ISong *newSong = new Song("song.wav");
    playlist->addSong(newSong);
    EXPECT_TRUE(playlist->moveSongDown(index));
}

TEST_F(PlaylistTest, WhenSongIsMovedDownInValidIndex_ThenReturnsFalse)
{
    int index = -1;
    ISong *newSong = new Song("song.wav");
    playlist->addSong(newSong);
    EXPECT_FALSE(playlist->moveSongDown(index));
}

TEST_F(PlaylistTest, WhenSongIsMovedDownInsufficientSize_ThenReturnsFalse)
{
    int index = 2;
    ISong *newSong = new Song("song.wav");
    playlist->addSong(newSong);
    EXPECT_FALSE(playlist->moveSongDown(index));
}