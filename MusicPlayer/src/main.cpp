#include <iostream>
#include <vector>
#include <list>
#include <musicPlayer.h>
#include <SFML/Audio.hpp>
#include "SFMLWrapper.h"
#include "constants.h"

int getPlayerAction()
{
    int choice;
    std::cout << "1. Pause" << std::endl;
    std::cout << "2. Stop" << std::endl;
    std::cout << "3. Next" << std::endl;
    std::cout << "4. Previous" << std::endl;
    std::cout << "5. Replay" << std::endl;
    std::cout << "6. Exit" << std::endl;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    return choice;
}

int main()
{
    SFMLWrapper music;
    MusicPlayer player(music);

    int option;
    int index;
    do
    {
        std::cout << "Main Menu:\n"
                  << "1. Play Playlist\n"
                  << "2. Create Playlist\n"
                  << "3. Delete Playlist\n"
                  << "4. Update Playlist\n"
                  << "5. Exit\n"
                  << "Enter your choice: \n";

        std::cin >> option;
        std::cin.ignore();

        switch (option)
        {
        case 1:
            player.showPlaylist();
            std::cout << "Enter the number of the playlist to play: ";
            std::cin >> index;
            std::cin.ignore();
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
                    player.stopAndReset();
                    break;
                case PlaylistAction::NEXT:
                    player.playNextSong();
                    break;
                case PlaylistAction::PREVIOUS:
                    player.playPreviousSong();
                    break;
                case PlaylistAction::REPLAY:
                    player.stopAndReset();
                    break;
                case PlaylistAction::EXIT:
                    std::cout << "Exiting the player." << std::endl;
                    break;
                default:
                    std::cerr << "Invalid action. Please try again." << std::endl;
                }
            } while (action != PlaylistAction::EXIT);

            break;
        case 2:
            player.createPlaylist();
            break;

        case 3:
            player.showPlaylist();
            std::cout << "Enter the number of the playlist to delete: ";
            std::cin >> index;
            std::cin.ignore();
            player.deletePlaylist(index);
            break;
        case 4:
            player.showPlaylist();
            std::cout << "Enter the number of the playlist to update: ";
            std::cin >> index;
            std::cin.ignore();
            player.updatePlaylist(index);
            break;
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
