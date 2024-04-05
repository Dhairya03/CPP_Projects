#include "playlist.h"
#include <iostream>

Playlist::Playlist() {}

Playlist::Playlist(std::string name) : name(name) {}

bool Playlist::addSong(ISong *song)
{
    bool isAdded = false;
    songs.push_back(song);
    isAdded = true;
    return isAdded;
}

void Playlist::displaySongs() const
{
    std::cout << "Songs in Playlist '" << name << "':" << std::endl;
    for (const auto &song : songs)
    {
        std::cout << song->getTitle() << std::endl;
    }
}

bool Playlist::deleteSong(int index)
{
    bool isDeleted = false;
    if (index >= 0 && index < songs.size())
    {
        songs.erase(songs.begin() + index);
        std::cout << "Song deleted successfully." << std::endl;
        isDeleted = true;
    }
    else
    {
        std::cout << "Invalid song index." << std::endl;
    }
    return isDeleted;
}

bool Playlist::updatePlaylistName(const std::string &newName)
{
    bool isNameUpdated = false;
    name = newName;
    std::cout << "Playlist name updated successfully." << std::endl;
    isNameUpdated = true;
    return isNameUpdated;
}

bool Playlist::moveSongUp(int index)
{
    bool isSongMovedUp = false;
    if (index > 0 && index < songs.size())
    {
        std::swap(songs[index], songs[index - 1]);
        std::cout << "Song moved up successfully." << std::endl;
        isSongMovedUp = true;
    }
    else
    {
        std::cout << "Invalid song index." << std::endl;
    }
    return isSongMovedUp;
}

bool Playlist::moveSongDown(int index)
{
    bool isSongMovedDown = false;
    if (index >= 0 && index < songs.size() - 1)
    {
        std::swap(songs[index], songs[index + 1]);
        std::cout << "Song moved down successfully." << std::endl;
        isSongMovedDown = true;
    }
    else
    {
        std::cout << "Invalid song index." << std::endl;
    }
    return isSongMovedDown;
}

std::string Playlist::getName() const
{
    return name;
}

const std::vector<ISong *> Playlist::getSongs() const
{
    return songs;
}
