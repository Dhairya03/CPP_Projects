#include <iostream>
#include <vector>
#include <list>
#include <musicPlayer.h>
#include <SFML/Audio.hpp>
#include "SFMLWrapper.h"
#include "constants.h"
#include "inputValidator.h"

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
    ILibraryWrapper *wrapper=&music;
    MusicPlayer player(music);
    std::vector<Song> playlist;
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
                std::cout << "Enter valid choice";
        }

        switch (option)
        {
        case 1:
        {
            player.showPlaylist();
            while (true)
            {
                std::cout << "Enter the number of the playlist to play: ";
                std::cin >> index;
                if (inputValidator.isValidInput())
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
                    player.playNextSong();
                    break;
                case PlaylistAction::PREVIOUS:
                    player.playPreviousSong();
                    break;
                case PlaylistAction::REPLAY:
                    player.replay();
                    break;
                case PlaylistAction::EXIT:
                    std::cout << "Exiting the player." << std::endl;
                    break;
                default:
                    std::cerr << "Invalid action. Please try again." << std::endl;
                }
            } while (action != PlaylistAction::EXIT);

            break;
        }
        case 2:
        {
            std::string name;
            std::cout << "Enter the name of the new playlist: ";
            getline(std::cin, name);

            std::cout << "Enter songs to add to the playlist (Enter -1 to finish):\n";
            int choice;
            std::string song;
            do
            {
                std::cout << "Available Songs:" << std::endl;
                for (int i = 0; i < player.allSongs.size(); ++i)
                {
                    std::cout << i + 1 << ". " << player.allSongs[i].getTitle() << std::endl;
                }
                std::cout << "Add song: ";
                while (true)
                {
                    std::cin >> choice;
                    if (inputValidator.isValidInput())
                        break;
                    else
                        std::cout << "Enter valid choice";
                }
                getline(std::cin, song);
                if (choice != -1)
                {
                    playlist.push_back(player.allSongs[choice - 1]);
                }
            } while (choice != -1);
            player.createPlaylist(name, playlist);

            break;
        }
        case 3:
        {
            player.showPlaylist();
            std::cout << "Enter the number of the playlist to delete: ";
            while (true)
            {
                std::cin >> index;
                if (inputValidator.isValidInput())
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
                if (inputValidator.isValidInput())
                    break;
                else
                    std::cout << "Enter valid choice";
            }

            std::cout << "Update Menu:\n"
                      << "1. Update Playlist Name\n"
                      << "2. Move Song Up\n"
                      << "3. Move Song Down\n"
                      << "Enter your choice: \n";

            int option;
            std::cin >> option;
            std::cin.ignore();
            player.updatePlaylist(index, option);
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
