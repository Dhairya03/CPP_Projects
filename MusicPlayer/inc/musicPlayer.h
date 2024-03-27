#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

#include <vector>
#include "playlist.h"
#include "song.h"
#include <SFML/Audio.hpp>
#include "ILibraryWrapper.h"
#include "constants.h"

class MusicPlayer
{
private:
    std::vector<Playlist> playlists;
    std::vector<Song> allSongs;
    ILibraryWrapper &music;
    Playlist *currentPlaylist=nullptr;
    int currentSongIndex;

    void savePlaylistsToFile(const std::vector<Playlist> &playlists);
    void loadPlaylistsFromFile(std::vector<Playlist> &playlists);
    void loadSongsFromFile(std::vector<Song> &allSongs);

public:
    MusicPlayer(ILibraryWrapper &);
    bool playSong(const std::string &songFile);
    void togglePause();
    void stopAndReset();
    void playNextSong();
    void playPreviousSong();
    void showPlaylist();
    bool playPlaylist(int);
    bool createPlaylist();
    bool deletePlaylist(int);
    bool updatePlaylist(int);
};

#endif
