#include "MusicLoader.h"
#include <iostream>
#include <fstream>
#include "playlist.h"

std::vector<IPlaylist *> &MusicLoader::loadPlaylistsFromFile(std::vector<IPlaylist *> &playlists)
{
    std::ifstream file("/home/dhairyagupta/training/c-_dhairyagupta/MusicPlayer/src/playlists.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            IPlaylist *playlist = new Playlist(line);
            while (getline(file, line) && !line.empty())
            {
                ISong *song = new Song(line);
                playlist->addSong(song);
            }
            playlists.push_back(playlist);
        }
        file.close();
    }
    else
    {
        std::cout << "No playlists found." << std::endl;
    }
    return playlists;
}

std::vector<ISong *> &MusicLoader::loadSongsFromFile(std::vector<ISong *> &allSongs)
{
    std::ifstream file("/home/dhairyagupta/training/c-_dhairyagupta/MusicPlayer/src/songs.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            ISong *song = new Song(line);
            allSongs.push_back(song);
        }
        file.close();
    }
    else
    {
        std::cout << "No songs found." << std::endl;
    }
    return allSongs;
}
