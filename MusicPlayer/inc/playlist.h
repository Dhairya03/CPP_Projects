#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "song.h"
#include <fstream>

class Playlist
{
private:
    std::string name;
    std::vector<Song> songs;

public:
    Playlist(std::string _name);
    bool addSong(const Song &song);
    bool displaySongs() const;
    bool deleteSong(int index);
    bool updatePlaylistName(const std::string &newName);
    bool moveSongUp(int index);
    bool moveSongDown(int index);
    std::string getName() const;
    const std::vector<Song> &getSongs() const;
};

#endif