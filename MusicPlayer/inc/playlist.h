#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <string>
#include <vector>
#include "song.h"
#include <fstream>
#include "IPlaylist.h"

class Playlist : public IPlaylist
{
private:
    std::string name;
    std::vector<ISong *> songs;

public:
    Playlist();
    Playlist(std::string _name);
    bool addSong( ISong *song);
    void displaySongs() const;
    bool deleteSong(int index);
    bool updatePlaylistName(const std::string &newName);
    bool moveSongUp(int index);
    bool moveSongDown(int index);
    std::string getName() const;
    const std::vector<ISong *> getSongs() const;
};

#endif