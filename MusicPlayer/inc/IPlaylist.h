#ifndef I_PLAYLIST_H
#define I_PLAYLIST_H

#include <string>
#include <vector>
#include "song.h"
#include <fstream>

class IPlaylist
{
public:
    virtual bool addSong(ISong *song) = 0;
    virtual void displaySongs() const = 0;
    virtual bool deleteSong(int index) = 0;
    virtual bool updatePlaylistName(const std::string &newName) = 0;
    virtual bool moveSongUp(int index) = 0;
    virtual bool moveSongDown(int index) = 0;
    virtual std::string getName() const = 0;
    virtual const std::vector<ISong *> getSongs() const = 0;
};

#endif