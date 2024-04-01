#include "musicPlayer.h"
#include <iostream>
#include <algorithm>
#include <fstream>

MusicPlayer::MusicPlayer(ILibraryWrapper &music) : music(music)
{
    loadPlaylistsFromFile(playlists);
    loadSongsFromFile(allSongs);
}

bool MusicPlayer::getIsPlaying()
{
    return isPlaying;
}

bool MusicPlayer::playSong(const Song &songFile)
{
    bool isPlayed = false;
    if (!music.openFromFile(songFile.getTitle()))
    {
        std::cerr << "Failed to load " << songFile.getTitle() << std::endl;
    }
    else
    {
        std::cout << "Now playing: " << songFile.getTitle() << std::endl;
        music.play();
        isPlayed = true;
        isPlaying = true;
    }
    return isPlayed;
}

bool MusicPlayer::togglePause()
{
    bool isPaused = false;
    if (getIsPlaying())
    {
        if (music.pause())
        {
            isPlaying = false;
            isPaused = true;
        }
    }
    else
    {
        if (music.play())
            isPlaying = true;
    }
    return isPaused;
}

bool MusicPlayer::stop()
{
    bool isStopped = false;
    if (music.stop())
        isStopped = true;
    return isStopped;
}

bool MusicPlayer::replay()
{
    bool isReplayed = false;
    if (music.stop())
    {
        if (music.play())
            isReplayed = true;
        else
            isReplayed = false;
    }
    return isReplayed;
}

bool MusicPlayer::playNextSong()
{
    bool isNextPlayed = false;
    if (currentSongIndex < currentPlaylist->getSongs().size() - 1)
    {
        ++currentSongIndex;
        music.stop();
        isNextPlayed = playSong(currentPlaylist->getSongs()[currentSongIndex]);
    }
    else
    {
        std::cout << "End of playlist reached." << std::endl;
    }
    return isNextPlayed;
}

bool MusicPlayer::playPreviousSong()
{
    bool isPreviousPlayed = false;
    if (currentSongIndex > 0)
    {
        --currentSongIndex;
        music.stop();
        isPreviousPlayed = playSong(currentPlaylist->getSongs()[currentSongIndex]);
    }
    else
    {
        std::cout << "Beginning of playlist reached." << std::endl;
    }
    return isPreviousPlayed;
}

bool MusicPlayer::playPlaylist(int index)
{
    bool isPlaylistPlayed = false;
    if (index >= 1 && index <= playlists.size())
    {
        currentPlaylist = &playlists[index - 1];
        currentSongIndex = 0;
        if (playSong(currentPlaylist->getSongs()[currentSongIndex]))
        {
            isPlaylistPlayed = true;
        }
    }
    else
    {
        std::cerr << "Invalid playlist number." << std::endl;
    }
    return isPlaylistPlayed;
}

bool MusicPlayer::createPlaylist(std::string name, std::vector<Song> &songs)
{
    bool isPlaylistCreated = false;
    Playlist playlist(name);
    if (songs.size() > 0)
    {
        for (int index = 0; index < songs.size(); index++)
        {
            playlist.addSong(songs[index]);
            isPlaylistCreated = true;
        }

        playlists.push_back(playlist);
        savePlaylistsToFile(playlists);
        std::cout << "Playlist '" << name << "' created successfully." << std::endl;
    }
    else
    {
        std::cout << "Playlist not created" << std::endl;
    }
    return isPlaylistCreated;
}

bool MusicPlayer::deletePlaylist(int choice)
{
    bool isDeleted = false;
    if (choice >= 1 && choice <= playlists.size())
    {
        playlists.erase(playlists.begin() + choice - 1);
        savePlaylistsToFile(playlists);
        isDeleted = true;
    }
    else
    {
        isDeleted = false;
    }
    return isDeleted;
}

bool MusicPlayer::updatePlaylist(int choice, int option)
{
    bool isUpdated = false;
    if (choice >= 1 && choice <= playlists.size())
    {
        Playlist &playlist = playlists[choice - 1];

        switch (option)
        {
        case 1:
        {
            std::string newName;
            std::cout << "Enter the new name for the playlist: ";
            getline(std::cin, newName);
            playlist.updatePlaylistName(newName);
            savePlaylistsToFile(playlists);
            std::cout << "Playlist name updated successfully." << std::endl;
            isUpdated = true;
        }
        break;
        case 2:
        {
            int songIndex;
            std::cout << "Enter the index of the song to move up: ";
            std::cin >> songIndex;
            std::cin.ignore();

            playlist.moveSongUp(songIndex);
            savePlaylistsToFile(playlists);
            isUpdated = true;
        }
        break;
        case 3:
        {
            int songIndex;
            std::cout << "Enter the index of the song to move down: ";
            std::cin >> songIndex;
            std::cin.ignore();

            playlist.moveSongDown(songIndex);
            savePlaylistsToFile(playlists);
            isUpdated = true;
        }
        break;
        default:
            std::cerr << "Invalid choice. Please try again." << std::endl;
            break;
        }
    }
    else
    {
        std::cerr << "Invalid playlist number." << std::endl;
    }
    return isUpdated;
}

void MusicPlayer::showPlaylist()
{
    std::cout << "Available Playlists:" << std::endl;
    for (int i = 0; i < playlists.size(); ++i)
    {
        std::cout << i + 1 << ". " << playlists[i].getName() << std::endl;
    }
}

void MusicPlayer::savePlaylistsToFile(const std::vector<Playlist> &playlists)
{
    std::ofstream file("/home/dhairyagupta/training/c-_dhairyagupta/MusicPlayer/src/playlists.txt");
    if (file.is_open())
    {
        for (const auto &playlist : playlists)
        {
            file << playlist.getName() << std::endl;
            for (const auto &song : playlist.getSongs())
            {
                file << song.getTitle() << std::endl;
            }
            file << std::endl;
        }
        file.close();
    }
    else
    {
        std::cout << "Error: Unable to save playlists to file." << std::endl;
    }
}

void MusicPlayer::loadPlaylistsFromFile(std::vector<Playlist> &playlists)
{
    std::ifstream file("/home/dhairyagupta/training/c-_dhairyagupta/MusicPlayer/src/playlists.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            Playlist playlist(line);
            while (getline(file, line) && !line.empty())
            {
                playlist.addSong(line);
            }
            playlists.push_back(playlist);
        }
        file.close();
    }
    else
    {
        std::cout << "No playlists found." << std::endl;
    }
}

void MusicPlayer::loadSongsFromFile(std::vector<Song> &allSongs)
{
    std::ifstream file("/home/dhairyagupta/training/c-_dhairyagupta/MusicPlayer/src/songs.txt");
    if (file.is_open())
    {
        std::string line;
        while (getline(file, line))
        {
            Song song(line);
            allSongs.push_back(song);
        }
        file.close();
    }
    else
    {
        std::cout << "No songs found." << std::endl;
    }
}
