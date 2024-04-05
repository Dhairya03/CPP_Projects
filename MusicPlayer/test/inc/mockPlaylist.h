#ifndef MOCK_PLAYLIST_H
#define MOCK_PLAYLIST_H

#include <gmock/gmock.h>
#include "IPlaylist.h"
#include "song.h"

class MockPlaylist : public IPlaylist
{
public:
    MOCK_METHOD(bool, addSong, (ISong *), (override));
    MOCK_METHOD(void, displaySongs, (), (const));
    MOCK_METHOD(bool, deleteSong, (int), (override));
    MOCK_METHOD(bool, updatePlaylistName, (const std::string &), (override));
    MOCK_METHOD(bool, moveSongUp, (int), (override));
    MOCK_METHOD(bool, moveSongDown, (int), (override));
    MOCK_METHOD(std ::string, getName, (), (const));
    MOCK_METHOD(const std::vector<ISong *>, getSongs, (), (const));
};

#endif