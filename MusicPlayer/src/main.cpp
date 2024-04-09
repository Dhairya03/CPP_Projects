#include <iostream>
#include <vector>
#include <list>
#include <musicPlayer.h>
#include <SFML/Audio.hpp>
#include "SFMLWrapper.h"
#include "constants.h"
#include "inputValidator.h"
#include "MusicLoader.h"

int getPlayerAction()
{
    InputValidator inputValidator;
    int choice;
    while (true)
    {
        std::cout << "1. Pause/Play\n"
                  << "2. Stop\n"
                  << "3. Next\n"
                  << "4. Previous\n"
                  << "5. Replay\n"
                  << "6. Exit\n"
                  << "Enter your choice:\n ";
        std::cin >> choice;
        if (inputValidator.isValidInput())
            break;
        else
        {
            std::cout << "Enter correct choice";
        }
    }
    return choice;
}

int main()
{
    SFMLWrapper music;
    MusicLoader loader;
    std::vector<IPlaylist *> allPlaylists;
    std::vector<ISong *> allSongs;
    MusicPlayer player(music, loader.loadPlaylistsFromFile(allPlaylists), loader.loadSongsFromFile(allSongs));
    std::vector<ISong *> songPlaylist;
    InputValidator inputValidator;
    int option;
    int index;
    do
    {
        while (true)
        {
            std::cout << "Main Menu:\n"
                      << "1. Play Playlist\n"
                      << "2. Create Playlist\n"
                      << "3. Delete Playlist\n"
                      << "4. Update Playlist\n"
                      << "5. Exit\n"
                      << "Enter your choice: \n";

            std::cin >> option;
            if (inputValidator.isValidInput())
                break;
            else
                std::cout << "Enter valid input" << std::endl;
        }
        switch (option)
        {
        case 1:
        {
            player.showPlaylist();
            std::cout << "Enter the number of the playlist to play: ";
            while (true)
            {
                std::cin >> index;
                if (inputValidator.isValidInput() && player.isValidPlaylistIndex(index))
                    break;
                else
                    std::cout << "Enter valid choice";
            }
            player.playPlaylist(index);
            PlaylistAction action;
            do
            {
                action = static_cast<PlaylistAction>(getPlayerAction());
                switch (action)
                {
                case PlaylistAction::PAUSE:
                    player.togglePause();
                    break;
                case PlaylistAction::STOP:
                    player.stop();
                    break;
                case PlaylistAction::NEXT:
                    music.stop();
                    player.playNextSong();
                    break;
                case PlaylistAction::PREVIOUS:
                    music.stop();
                    player.playPreviousSong();
                    break;
                case PlaylistAction::REPLAY:
                    player.replay();
                    break;
                case PlaylistAction::EXIT:
                    player.stop();
                    std::cout << "Exiting the player." << std::endl;
                    break;
                default:
                    std::cerr << "Invalid action. Please try again." << std::endl;
                    break;
                }
            } while (action != PlaylistAction::EXIT);
            break;
        }
        case 2:
        {
            bool isValidName = false;
            std::string name;
            std::cout << "Enter the name of the new playlist: ";
            std::cin >> name;
            for (int index = 0; index < allPlaylists.size(); index++)
            {
                if (name == allPlaylists[index]->getName())
                {
                    isValidName = false;
                    std::cout << "Playlist already exists" << std::endl;
                    break;
                }
                else
                {
                    isValidName = true;
                }
            }
            if (isValidName)
            {
                std::cout << "Enter songs to add to the playlist (Enter -1 to finish):\n";
                int choice;
                do
                {
                    std::cout << "Available Songs:" << std::endl;
                    for (int i = 0; i < player.allSongs.size(); ++i)
                    {
                        std::cout << i + 1 << ". " << player.allSongs[i]->getTitle() << std::endl;
                    }
                    std::cout << "Add song: ";
                    while (true)
                    {
                        std::cin >> choice;
                        if (inputValidator.isValidInput() && (player.isValidSongIndex(choice) || choice == -1))
                            break;
                        else
                            std::cout << "Enter valid choice";
                    }
                    if (choice != -1)
                    {
                        songPlaylist.push_back(player.allSongs[choice - 1]);
                    }
                } while (choice != -1);
                player.createPlaylist(name, songPlaylist);
                songPlaylist.clear();
            }

            break;
        }
        case 3:
        {
            player.showPlaylist();
            std::cout << "Enter the number of the playlist to delete: ";
            while (true)
            {
                std::cin >> index;
                if (inputValidator.isValidInput() && player.isValidPlaylistIndex(index))
                    break;
                else
                    std::cout << "Enter valid choice";
            }
            if (player.deletePlaylist(index))
            {
                std::cout << "Playlist deleted successfully." << std::endl;
            }
            else
            {
                std::cerr << "Invalid playlist number." << std::endl;
            }
            break;
        }
        case 4:
        {
            player.showPlaylist();
            std::cout << "Enter the number of the playlist to update: ";
            while (true)
            {
                std::cin >> index;
                if (inputValidator.isValidInput() && player.isValidPlaylistIndex(index))
                    break;
                else
                    std::cout << "Enter valid choice";
            }
            int option;
            do
            {
                std::cout << "Update Menu:\n"
                          << "1. Update Playlist Name\n"
                          << "2. Move Song Up\n"
                          << "3. Move Song Down\n"
                          << "4. Add Song To Playlist\n"
                          << "5. Delete Song From Playlist\n"
                          << "6. Exit\n"
                          << "Enter your choice: \n";

                while (true)
                {
                    std::cin >> option;
                    if (inputValidator.isValidInput())
                        break;
                    else
                        std::cout << "Enter valid choice";
                }
                switch (option)
                {
                case 1:
                {
                    std::string newName;
                    std::cout << "Enter the new name for the playlist: ";
                    std::cin >> newName;
                    player.updatePlaylistName(index, newName);
                    break;
                }
                case 2:
                {
                    allPlaylists[index - 1]->displaySongs();
                    int songIndex;
                    std::cout << "Enter the index of the song to move up: ";
                    while (true)
                    {
                        std::cin >> songIndex;
                        if (inputValidator.isValidInput() && player.isValidSongIndex(index))
                            break;
                        else
                            std::cout << "Enter valid index" << std::endl;
                    }
                    player.shuffleSong(index, 1, songIndex);
                    allPlaylists[index - 1]->displaySongs();
                    break;
                }
                case 3:
                {
                    allPlaylists[index - 1]->displaySongs();
                    int songIndex;
                    std::cout << "Enter the index of the song to move down: ";
                    while (true)
                    {
                        std::cin >> songIndex;
                        if (inputValidator.isValidInput() && player.isValidSongIndex(index))
                            break;
                        else
                            std::cout << "Enter valid index" << std::endl;
                    }
                    player.shuffleSong(index, 2, songIndex);
                    allPlaylists[index - 1]->displaySongs();

                    break;
                }
                case 4:
                {
                    int songIndex;
                    std::cout << "Available Songs:" << std::endl;
                    for (int i = 0; i < player.allSongs.size(); ++i)
                    {
                        std::cout << i + 1 << ". " << player.allSongs[i]->getTitle() << std::endl;
                    }
                    std::cout << "Enter the index of the song to add: ";
                    while (true)
                    {
                        std::cin >> songIndex;
                        if (inputValidator.isValidInput() && player.isValidSongIndex(index))
                            break;
                        else
                            std::cout << "Enter valid index" << std::endl;
                    }
                    allPlaylists[index - 1]->addSong(allSongs[songIndex - 1]);
                    allPlaylists[index - 1]->displaySongs();
                    std::cout << "Song added successfully" << std::endl;
                    break;
                }
                case 5:
                {
                    int songIndex;
                    allPlaylists[index - 1]->displaySongs();
                    std::cout << "Enter the index of the song to delete: ";
                    while (true)
                    {
                        std::cin >> songIndex;
                        if (inputValidator.isValidInput() && player.isValidSongIndex(index))
                            break;
                        else
                            std::cout << "Enter valid index" << std::endl;
                    }
                    allPlaylists[index - 1]->deleteSong(songIndex - 1);
                    allPlaylists[index - 1]->displaySongs();
                    std::cout << "Song deleted successfully" << std::endl;
                    break;
                }
                case 6:
                    break;
                default:
                    std::cerr << "Invalid choice. Please try again." << std::endl;
                    break;
                }
            } while (option != 6);
            break;
        }
        case 5:
            std::cout << "Exiting Successfully" << std::endl;
            break;
        default:
            std::cout << "Invalid option. Please try again." << std::endl;
            break;
        }
    } while (option != 5);

    return 0;
}
