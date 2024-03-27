#include "musicPlayer.h"
#include <iostream>
#include <algorithm>
#include <fstream>

MusicPlayer::MusicPlayer(ILibraryWrapper &music) : music(music)
{
    loadPlaylistsFromFile(playlists);
    loadSongsFromFile(allSongs);
}

bool MusicPlayer::playSong(const std::string &songFile)
{
    if (!music.openFromFile(songFile))
    {
        std::cerr << "Failed to load " << songFile << std::endl;
        return false;
    }
    std::cout << "Now playing: " << songFile << std::endl;
    music.play();
    return true;
}

void MusicPlayer::togglePause()
{
    if (music.getStatus() == sf::SoundSource::Playing){
        music.pause();
        std::cout<<"paused";
    }
    else
        music.play();
}

void MusicPlayer::stopAndReset()
{
    music.stop();
            std::cout<<"stopped";

    music.play();
}

void MusicPlayer::playNextSong()
{
    if (currentSongIndex < currentPlaylist->getSongs().size() - 1)
    {
        ++currentSongIndex;
    }
    else
    {
        std::cout << "End of playlist reached." << std::endl;
        return;
    }
    stopAndReset();
}

void MusicPlayer::playPreviousSong()
{
    if (currentSongIndex > 0)
    {
        --currentSongIndex;
    }
    else
    {
        std::cout << "Beginning of playlist reached." << std::endl;
        return;
    }
    stopAndReset();
}

bool MusicPlayer::playPlaylist(int index)
{

    if (index >= 1 && index <= playlists.size())
    {
        currentPlaylist = &playlists[index - 1];
        currentSongIndex = 0;
        if (!playSong(currentPlaylist->getSongs()[currentSongIndex]))
        {
            return false;
        }
    }
    else
    {
        std::cerr << "Invalid playlist number." << std::endl;
        return false;
    }
    return true;
}

bool MusicPlayer::createPlaylist()
{
    std::string name;
    std::cout << "Enter the name of the new playlist: ";
    getline(std::cin, name);

    Playlist playlist(name);

    std::cout << "Enter songs to add to the playlist (Enter 'done' to finish):\n";
    std::string song;
    do
    {
        std::cout << "Available Songs:" << std::endl;
        for (int i = 0; i < allSongs.size(); ++i)
        {
            std::cout << allSongs[i].getTitle() << std::endl;
        }
        std::cout << "Add song: ";
        getline(std::cin, song);
        if (song != "done")
        {
            playlist.addSong(song);
        }
    } while (song != "done");

    playlists.push_back(playlist);
    savePlaylistsToFile(playlists);
    std::cout << "Playlist '" << name << "' created successfully." << std::endl;
}

bool MusicPlayer::deletePlaylist(int choice)
{
    if (choice >= 1 && choice <= playlists.size())
    {
        playlists.erase(playlists.begin() + choice - 1);
        savePlaylistsToFile(playlists);
        std::cout << "Playlist deleted successfully." << std::endl;
    }
    else
    {
        std::cerr << "Invalid playlist number." << std::endl;
    }
}

bool MusicPlayer::updatePlaylist(int choice)
{
    if (choice >= 1 && choice <= playlists.size())
    {
        Playlist &playlist = playlists[choice - 1];

        std::cout << "1. Update Playlist Name" << std::endl;
        std::cout << "2. Move Song Up" << std::endl;
        std::cout << "3. Move Song Down" << std::endl;
        std::cout << "Enter your choice: ";

        int option;
        std::cin >> option;
        std::cin.ignore();

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
    std::ofstream file("playlists.txt");
    if (file.is_open())
    {
        for (const auto &playlist : playlists)
        {
            file << playlist.getName() << std::endl;
            for (const auto &song : playlist.getSongs())
            {
                file << song << std::endl;
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
        std::cout << "opened";
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
