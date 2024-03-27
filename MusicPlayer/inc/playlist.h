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
    void addSong(const Song &song);
    void displaySongs() const;
    void deleteSong(int index);
    void updatePlaylistName(const std::string &newName);
    void moveSongUp(int index);
    void moveSongDown(int index);
    std::string getName() const;
    const std::vector<Song> &getSongs() const;
};

#endif