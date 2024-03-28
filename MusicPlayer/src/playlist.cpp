#include "playlist.h"
#include <iostream>

Playlist::Playlist(std::string name) : name(name) {}

bool Playlist::addSong(const Song &song)
{
    songs.push_back(song);
}

bool Playlist::displaySongs() const
{
    std::cout << "Songs in Playlist '" << name << "':" << std::endl;
    for (const auto &song : songs)
    {
        std::cout << song.getTitle() << std::endl;
    }
}

bool Playlist::deleteSong(int index)
{
    if (index >= 0 && index < songs.size())
    {
        songs.erase(songs.begin() + index);
        std::cout << "Song deleted successfully." << std::endl;
    }
    else
    {
        std::cout << "Invalid song index." << std::endl;
    }
}

bool Playlist::updatePlaylistName(const std::string &newName)
{
    name = newName;
    std::cout << "Playlist name updated successfully." << std::endl;
}

bool Playlist::moveSongUp(int index)
{
    if (index > 0 && index < songs.size())
    {
        std::swap(songs[index], songs[index - 1]);
        std::cout << "Song moved up successfully." << std::endl;
    }
    else
    {
        std::cout << "Invalid song index." << std::endl;
    }
}

bool Playlist::moveSongDown(int index)
{
    if (index >= 0 && index < songs.size() - 1)
    {
        std::swap(songs[index], songs[index + 1]);
        std::cout << "Song moved down successfully." << std::endl;
    }
    else
    {
        std::cout << "Invalid song index." << std::endl;
    }
}

std::string Playlist::getName() const
{
    return name;
}

const std::vector<Song> &Playlist::getSongs() const
{
    return songs;
}

